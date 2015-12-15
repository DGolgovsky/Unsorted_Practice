#include <stdio.h>

#define SUM(a,b) a+b
#define Print(x) printf("%d ", x)

int main()
{
    int a = 2, b = 3, c = 5;
    
    Print(SUM(a,b));
    Print(SUM(a,b)*c);
    Print(c*SUM(a,b));
    
    return 0;
}
