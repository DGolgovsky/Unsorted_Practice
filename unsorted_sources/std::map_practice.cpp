#include <iostream>
#include <map>

using std::string;

int main(int argc, char *argv[]) {
    std::map <string, string> m;
    m["cpp"] = "C++ source file";
    m["cc"] = m["cpp"];
    m["java"] = "Java source file";

    std::cout << "key> ";

    string key = "";
    string val = "";
    while (std::cin >> key) {
        string r = m[key];
        if (r != "") {
            std::cout << r;
        } else {
            std::cout << "Unknown key. Add new value: [" << key << "] = ";
            std::cin >> val;
            m[key] = val;
            std::cout << "Added new [" << key << "] = \"" << m[key]
                      << "\".";
        }
        std::cout << "\nkey> ";
    }
    return 0;
}
