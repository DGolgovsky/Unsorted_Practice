#include <iostream>
#include <string>
#include <set>
#include <boost/algorithm/string.hpp>


// Function suggested by user 'mshrbkv':
bool isWordSeparator(char c) {
    return std::isspace(c) || std::ispunct(c);
}

// This is used to make the set case-insensitive.
// Alternatively you could call boost::to_lower() to make the
// string all lowercase before calling boost::split(). 
struct IgnoreCaseCompare {
    bool operator()( const std::string& a, const std::string& b ) const {
        return boost::ilexicographical_compare( a, b );
    }
};

int main()
{
    static constexpr auto s = R"(
    The time has come, the Walrus said,
        to talk of many things...
    )";

    // Define a set that will contain only unique strings, ignoring case.
    std::set< std::string, IgnoreCaseCompare > words;

    // Split the string by using your isWordSeparator function
    // to define the delimiters. token_compress_on collapses multiple
    // consecutive delimiters into only one. 
    boost::split( words, s, isWordSeparator, boost::token_compress_on );

    // Now the set contains only the unique words.
    std::cout << "Number of Words: " << words.size() << std::endl;
    for( auto& w : words )
        std::cout << w << std::endl;

    return 0;
}