#include <cstring>
#include <ifstream>

void printLast10Lines(char* fileName) {
    
    const int K = 10;
    ifstream file (fileName);
    string L[K];
    int size = 0;
    
    /* читаем файл построчно в круговой массив */
    while (file.good()) {
        getline(file, L[size % K]);
        size++;
    }
    
    /* вычисляем начало кругового массива и его размер */
    int start = size > K ? (size % K) : 0;
    int count = min(K, size);
    
    /* выводим элементы в порядке чтения */
    for (int i = 0; i < count; i++) {
        cout << L[(start + i) % K] << endl;
    }
}
