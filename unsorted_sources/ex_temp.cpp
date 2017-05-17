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
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    string TEMPS; // the N temperatures expressed as integers ranging from -273 to 5526
    getline(cin, TEMPS);
    string arr[N];
    int i = 0, k = 0;
    int min_val = 5526;
    if (N == 0) min_val = 0;
    //cout << TEMPS << endl;
    
    while (TEMPS[k] != '\0') {
        if ((TEMPS[k] >= '0' && TEMPS[k] <= '9') || TEMPS[k] == '-') {
            arr[i] += TEMPS[k];
        } else {
            int a = atoi( arr[i].c_str() );
            //cout << arr[i] << "," << a << ";";
            if (min_val > abs(a)) min_val = a;
            i++;
            arr[i] = "";
        }
        k++;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << "!" << min_val << endl;
}
