#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    string arr[H];
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        arr[i] = ROW;
    }
    string out_text[H];
    int i = 0;
    
    while (T[i] != '\0') { //word
        int a = toupper(T[i]);
        if (a < 65 || a > 90) a = 91;
        for (int k = 0; k < H; k++) { //lines
            for (int z = 0; z < L; z++) //chars
                out_text[k] += arr[k][(a-65)*L + z];
        }
        i++;
    }
    for (int i = 0; i < H; i++) {
        cout << out_text[i] << endl;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}
