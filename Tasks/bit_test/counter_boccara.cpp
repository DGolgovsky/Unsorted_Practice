#include <boost/algorithm/string.hpp>
#include <map>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

bool is_delimiter(char c)
{
    auto const is_allowed = isalnum(c) || c == '_';
    return !is_allowed;
}

std::map<std::string, size_t>
count_words(std::vector<std::string> const &words)
{
    std::map<std::string, size_t> word_count{};
    for (auto const &word : words)
        ++word_count[word];
    return word_count;
}

using word_count_t = std::vector<std::pair<std::string, size_t>>;

word_count_t get_word_count(std::string const &str)
{
    std::vector<std::string> words;
    boost::split(words, str, is_delimiter, boost::token_compress_on);
    words.erase(std::remove(begin(words), end(words), ""), end(words));

    auto const count = count_words(words);

    auto sorted_count = word_count_t(begin(count), end(count));
    std::sort(begin(sorted_count), end(sorted_count),
              [](auto const &p1, auto const &p2) {
                  return p1.second > p2.second;
              });

    return sorted_count;
}

auto print(word_count_t const &entries)
{
    std::stringstream ss;
    if (entries.empty()) return ss.str();

    for (auto const &entry : entries)
        ss << std::setw(2) << std::right << entry.second << ' ' << entry.first << '\n';
    return ss.str();
}

int main(int argc, char** argv)
{
    std::string entry_string;
    auto ifile = "in.txt";
    auto ofile = "out.txt";

    if (argc > 1)
        ifile = argv[1];
    std::ifstream input_file(ifile, std::ios_base::out);

    if (!input_file)
        return EXIT_FAILURE;

    std::string tmp;
    while(!input_file.eof())
    {
        getline(input_file, tmp);
        entry_string += tmp;
    }
    input_file.close();

    if (argc == 3)
        ofile = argv[2];
    std::ofstream output_file(ofile, std::ios_base::app);
    output_file << print(get_word_count(entry_string));

    output_file.flush();
    output_file.close();

    return EXIT_SUCCESS;
}