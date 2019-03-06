int **create_array2d(size_t a, size_t b) {
    int **m = new int *[a];
    m[0] = new int[a * b];
    for (size_t i = 1; i != a; ++i)
        m[i] = m[i - 1] + b;
    return m;
}

void free_array2d(int **m, size_t a, size_t b) {
    delete[] m[0];
    delete[] m;
}

int main() {
    return 0;
}
