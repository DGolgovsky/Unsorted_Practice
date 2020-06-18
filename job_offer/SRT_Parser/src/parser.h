#ifndef SRT_PARSER_H
#define SRT_PARSER_H

#include "nlohmann/json.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

namespace srt
{
	class parser final
	{
		using json = nlohmann::json;

	private:
		std::string out_file;
		json o_json;

	public:
		parser() = default;

		explicit parser(const std::string &&file);

		~parser() = default;

		void write(std::string const &ofile);

		void write();

		void serialize(uint64_t &message);

	private:
		template <typename T, typename U>
		void to_json(std::pair <T, U> &&it);

		void parse_reset(uint64_t &message);

		void parse_error(uint64_t &message);

		void parse_monthly(uint64_t &message);

		void parse_daily(uint64_t &message);
	};
}
#endif // SRT_PARSER_H
