#include <iostream>
#include <fstream>
#include <iomanip>
#include "clickhouse-cpp/clickhouse/client.h"
#include <string>
#include <nlohmann/json.hpp>
#include "converter.h"
#include "app_args.h"
#include "data_objects.h"

using namespace clickhouse;
using json = nlohmann::json;
using namespace fmt;
using namespace fmt::literals;

void to_json(std::string const &out_file,
             tv::target_audience const &ta,
             std::vector<tv::UInt64> const &event_ids,
             tv::Float64 const &cum_tvr,
             std::vector<json> &output_json)
{
  // Writing result in json
  json item_output_json;
  item_output_json["ta"] = ta;
  item_output_json["event"] = event_ids;
  item_output_json["cum_tvr"] = cum_tvr;
  output_json.push_back(item_output_json);
}

void from_json(std::string const &in_file, json &in_json)
{
  // Opening json file
  std::ifstream input_json_file;
  input_json_file.open(in_file);
  if (!input_json_file.is_open())
  {
    std::cout << "ERROR: Could not open json file!";
    exit(1);
  }

  // Reading json file
  input_json_file >> in_json;
  input_json_file.close();
}

int main(int argc, char * argv[]) {

  // Initialization of application arguments
  args app_args;
  reading_app_args(argc, argv, app_args);

  // Help
  if (!app_args.help.empty())
  {
    std::cout << app_args.help << std::endl;
    return 0;
  }

  // Initialize clickhouse client connection.
  ClientOptions opts;
  opts.SetHost(app_args.host);
  opts.SetDefaultDatabase(app_args.dbname);
  opts.SetPort(app_args.port);
  opts.SetUser(app_args.username);
  opts.SetPassword(app_args.password);
  clickhouse::Client client(opts);

  // Сreating DB schema
  if (app_args.schema_db)
  {
    tv::schema_db_create_tables(client);
    return 0;
  }

  // Input JSON
  json input_json;

  // Output JSON
  std::vector<json> output_json;

  // Reading input JSON file
  from_json(app_args.in_file, input_json);

  for (const auto &item_input_json: input_json)
  {
    // Input initialization
    tv::target_audience input_ta = item_input_json.at("ta");
    std::vector<tv::UInt64> input_event_ids = item_input_json.at("event");

    //select data: respondents_of_ta_events
    tv::respondents_of_ta_events respondents_of_ta_events;
    tv::respondent_of_ta_event::select_data(client, input_ta, input_event_ids, respondents_of_ta_events);

    // Calculation of Metrics
    //TVR(TA, i) = 100 * Audience(TA, i) / Size(TA)
    //Audience(TA, i) = sum(weights[j] * views[i, j] for j in TA) / lengths[i]
    //Cum_TVR(TA, events) = sum(TVR(TA, i) for i in events)

    tv::Float64 cum_tvr = 0;
    for(auto const &res_event: respondents_of_ta_events)
    {
      tv::Float64 audience = 0;
      tv::Float64 tvr = 0;
      for (auto res_weight_dur: res_event.respondents_weight_dur)
      {
        audience = audience + res_weight_dur;
      }
      audience = audience / res_event.event_duration;
      tvr = 100 * audience / res_event.respondents_weight_dur.size();
      cum_tvr = cum_tvr + tvr;
    }

    // Writing result in json
    to_json(app_args.out_file, input_ta, input_event_ids, cum_tvr, output_json);
  }

  // Write JSON to output_file
  std::ofstream ofs(app_args.out_file);
  ofs << std::setw(2) << output_json << std::endl;
  ofs.close();
  return 0;
}