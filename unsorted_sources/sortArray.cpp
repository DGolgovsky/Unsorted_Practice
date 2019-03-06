#include <iostream>

using namespace std;

int myAbs(int a) {
    int oldByte = (a >> 31) & 0x1;
    return -a * (1 + oldByte - 1) - a * (oldByte - 1);
}

int getMax(int a, int b) {
    return (a + b + myAbs(a - b)) / 2;
}

int getMin(int a, int b) {
    return (a + b - myAbs(a - b)) / 2;
}

int main() {
    int arr[] = {34, 12, 24, 65, 63, 22};
    int arraySize = (sizeof(arr) / sizeof(*arr));

    int maxPosition = 0;
    int maxElement = arr[0];
    int minValue = arr[0];
    for (int k = 0; k < arraySize; k++) {
        for (int i = k; i < arraySize; i++) {
            int newMax = getMax(maxElement, arr[i]);
            minValue = getMin(minValue, arr[i]);
            maxPosition = getMin((myAbs(newMax ^ maxElement) + 1) * (maxPosition + 1),
                                 (myAbs(newMax ^ arr[i]) + 1) * (i + 1)) - 1;
            maxElement = newMax;
        }
        int buf = arr[k];
        arr[k] = maxElement;
        arr[maxPosition] = buf;
        maxElement = minValue;
    }
    for (int a:arr) {
        cout << a << endl;
    }
    return 0;
}
