// Инициализация
int a[] = {1, 2, 3};
int a[3] = {1, 2, 3};

// Неявная инициализация
int b[5] = {1, 2, 3};
// equal
int b[5] = {1, 2, 3, 0, 0};

// С выделенными инициализаторами
int c[7] = {1, [5] = 10, 20, [1] = 2};
//equal
int c[7] = {1, 2, 0, 0, 0, 10, 20}

char c[N]
c[sizeof(c) - 1] == '\0'
