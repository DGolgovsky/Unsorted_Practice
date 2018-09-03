#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <iomanip>
#include <algorithm>

// Splitting transaction
std::vector<std::string> split(std::string const &str, char d)
{
    std::vector<std::string> r;
    
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}

// Write into stringstream for output
void writeln(std::ostream &os, const std::string &str)
{
    os << str.c_str() << '\n';
}

auto get_transaction(const std::string &i_str)
{
    //std::tuple<double,std::string,std::string,double,double> ret_val;

    std::vector<std::string> line = split(i_str, ';');

    double deposit = std::atof(line.at(0).c_str());
    std::string date = line.at(1);
    std::string account = line.at(2);
    double income = std::atof(line.at(3).c_str());
    double outcome = std::atof(line.at(4).c_str());

    return std::make_tuple(deposit,date,account,income,outcome);
}

int main(int argc, char **argv)
{
    std::string file_name = "in.txt";
    if (argc > 1)
        file_name = argv[1];

    std::ifstream ifs;
    ifs.open(file_name);

    if (!ifs.is_open()) {
        std::cerr << "Can't open input file\n";
        return 1;
    }

    std::stringstream ss;
    double balance = 0.0; // Current balance state

    std::string w_str = ""; // String to write into output stream
    std::string w_start_date;
    std::string w_end_date;

    for (std::string str; std::getline(ifs, str); ) {
        auto [deposit, date, account, income, outcome] = get_transaction(str);

        if (deposit != 0.0) {
            // Initialisation for new account
            balance = deposit;
            balance += income;
            balance -= outcome;
            w_start_date = date;
            w_end_date = date;
            continue;
        }
        double check = balance + income - outcome;
        if (check != balance) {
            // Splitting whitespaces
            account.erase(std::remove_if(account.begin(), account.end(), isspace), account.end());
            w_str = w_start_date + ";" + w_end_date + ";" + account + ";" + std::to_string(balance);
            writeln(ss, w_str);
            balance = check;
            w_start_date = date;
        }
        w_end_date = date;
    }

    std::ofstream ofs("out.txt", std::ios_base::trunc);
    if (ofs.is_open()) {
        ofs << ss.str();
    }

    return 0;
}
