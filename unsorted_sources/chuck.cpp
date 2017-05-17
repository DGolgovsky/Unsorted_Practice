#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int to_bin(int dec) {
    int bin = 0;
    for(int j = 0; dec > 0; j++) {
        bin += (dec % 2) * pow(10.0, j);
        dec /= 2;
    }
    return bin;
};

int main()
{
    string MESSAGE = "C A%";
//    getline(cin, MESSAGE);
    
    string line = "";
    for (int i = 0; MESSAGE[i] !='\0'; i++) {
		string letter = to_string(to_bin((int)MESSAGE[i]));
		if (letter.length() < 7)
			for (int l = 0; l < (7 - letter.length()); l++)
				letter =  "0" + letter;
        line += letter;
		cout << MESSAGE[i] << letter.length() << endl;
	}
    
    cout << line << endl;
    int i = 0;
    string out = "";
    int count = 1;
    while (line[i] != '\0') {
        char a = line[i];
        if (line[i+1] == a) {
            count++;
        } else {
            if (i > 0) out += " ";
            if (a == '1') out += "0";
            else out += "00";
            out += " ";
            for (int k = 0; k < count; k++) out += "0";
            count = 1;
        }
        i++;
    }
    
    cout << out << endl;
}
