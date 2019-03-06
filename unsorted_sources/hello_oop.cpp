#include <iostream>
#include <string>

using namespace std;

inline void pr_message(string s = "Hello, world!") {
    cout << "<< " << s << endl;
}

int main() {
    string s;
    cout << ">> ";
    cin >> s;
    pr_message(s);
    return 0;
}
