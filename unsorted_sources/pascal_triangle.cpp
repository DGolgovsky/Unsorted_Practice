#include <iostream>

using namespace std;

void w_spc(int w) {
    for (short i = 0; i < w; ++i)
        cout << " ";
}

double Cnk(int N, int K) {
    return ((N < K) ? 0 : ((K == 0) ? 1 : ((N - K + 1) / double(K) * Cnk(N, K - 1))));
}

int main(void) {
    int w = 39;
    int n;
    cin >> n;
    for (short j = 0; j <= n; ++j) {
        //w_spc(w);
        for (int m = 0; m < (n - j) * 4; m++) printf(" ");
        // w = w%5 ? w-1 : w-2;
        for (short i = 0; i <= j; ++i)
            cout << Cnk(j, i) << " ";
        cout << "\n";
    }

    return 0;
}

