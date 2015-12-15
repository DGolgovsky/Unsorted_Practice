/*#include <iostream>

int **create_array2d(const int& rows, const int& cols) 
{
   int **m = new int*[rows];
   for(int i = 0; i < rows; ++i)
      m[i] = new int [cols];
   return m;
}
 
int **transpose(const int * const * m_, const int& rows, const int& cols)
{
    int **mt_ = create_array2d(cols, rows);
 
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j)
            mt_[i][j] = m_[j][i];
    }
    
    return mt_;
}

int main()
{
    int R, C;
    std::cin >> R >> C;
    int **matr = create_array2d(R, C);
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < R; ++j)
            std::cin >> matr[i][j];
    }
    matr = transpose(matr, R, C);
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < R; ++j)
            std::cout << matr[i][j] << " ";
    return 0;
}
*/

#include <iostream>

int main()
{
    int R, C;
    std::cin >> R >> C;
    int matrix[R][C];
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            std::cin >> matrix[i][j];
	for (int i = 0; i < C; ++i)
        for (int j = 0; j < R; ++j)
            std::cout << matrix[j][i] << " ";
    return 0;
}
