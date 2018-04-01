#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> StringToVector(
        std::string theString,
        char separator)
{
    std::vector<std::string> vecsWords;

    std::stringstream ss(theString);
    std::string sIndivStr;
    while (getline(ss, sIndivStr, separator)) {
        vecsWords.push_back(sIndivStr);
    }

    return vecsWords;
}

std::string VectorToString(
        std::vector<std::string>& vec,
        char separator)
{
    std::string theString = "";
    for (auto cust : vec)
        theString += cust + separator;

    return theString;
}

std::string TrimWhitespace(std::string theString)
{
    std::string whitespaces(" \t\f\n\r");

    theString.erase(theString.find_last_not_of(whitespaces) + 1);
    theString.erase(0, theString.find_first_not_of(whitespaces));

    return theString;
}

std::vector<int> FindSubstringMatches(
        std::string theString,
        std::string substring)
{
    std::vector<int> matchingIndexes;
    int index = theString.find(substring, 0);
    while (index != std::string::npos) {
        matchingIndexes.push_back(index);
        index = theString.find(substring, index + 1);
    }

    return matchingIndexes;
}

std::string ReplaceAllSubstrings(
        std::string theString,
        std::string substring,
        std::string newString)
{
    std::vector<int> matches = FindSubstringMatches(theString, substring);

    if (!matches.empty()) {
        int lengthDifference = newString.size() - substring.size();
        int timesLooped = 0;
        for (auto index : matches) {
            theString.replace(
                    index + (timesLooped * lengthDifference),
                    substring.size(),
                    newString);
            timesLooped++;
        }
    }

    return theString;
}

std::string CaesarCipher(std::string theString, int step, bool method)
{
    if (method) { /* Encrypt */
        
    } else { /* Decrypt */

    }
    
    return theString;
}

int main(int, char const **)
{
    std::cout << "[0] EXAMPLE [StringToVector]:\n";
    { /* String to Vector example */
        std::vector<std::string> vec = StringToVector("This is a random string", ' ');
        for (unsigned int i = 0; i < vec.size(); ++i) {
            std::cout << vec[i] << '\n';
        }
    }

    std::cout << "\n[1] EXAMPLE [VectorToString]:\n";
    {
        std::vector<std::string> vCusts(3);
        vCusts[0] = "Bob";
        vCusts[1] = "Sue";
        vCusts[2] = "Tom";

        std::string sCusts = VectorToString(vCusts, ' ');
        std::cout << sCusts << '\n';
    }

    std::cout << "\n[2] EXAMPLE [TrimWhitespace]:\n";
    {
        std::string aStr = "       Just some random words        ";
        aStr = TrimWhitespace(aStr);
        std::cout << "*" << aStr << "*\n";
    }

    std::cout << "\n[3] EXAMPLE [FindSubstringMatches]:\n";
    {
        std::string phrase = "To be or not to be";
        std::vector<int> matches = FindSubstringMatches(phrase, "be");
        for (unsigned int i = 0; i < matches.size(); ++i) {
            std::cout << matches[i] << "\n";
        }
    }

    std::cout << "\n[4] EXAMPLE [ReplaceAllSubstrings]:\n";
    {
        std::cout << ReplaceAllSubstrings("to know or not to know", "know", "be") << '\n';
    }

    std::cout << "\n[5] EXAMPLE [What is it?]:\n";
    {
        char letterZ = 'z';
        char num3 = '3';
        char aSpace = ' ';

        std::cout << "Is z a letter or number: " <<
            isalnum(letterZ) << '\n';
        std::cout << "Is z a letter: " <<
            isalpha(letterZ) << '\n';
        std::cout << "Is z uppercase: " <<
            isupper(letterZ) << '\n';
        std::cout << "Is z lowercase: " <<
            islower(letterZ) << '\n';
        std::cout << "Is 3 a number: " <<
            isdigit(num3) << '\n';
        std::cout << "Is space a space: " <<
            isspace(aSpace) << '\n';
    }

    std::cout << "\n[6] EXAMPLE [CaesarCipher]:\n";
    {
        std::string theString = "Make me secret";
        std::string encryptedStr = CaesarCipher(theString, 5, true);
        std::string decryptedStr = CaesarCipher(encryptedStr, 5, false);

        std::cout << "Encrypted: " << encryptedStr << '\n';
        std::cout << "Decrypted: " << decryptedStr << '\n';
    }

    return 0;
}
