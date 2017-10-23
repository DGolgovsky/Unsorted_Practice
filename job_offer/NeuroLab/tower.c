#include <stdio.h>
#include <math.h>

// Hомер первого этажа по номеру блока
unsigned int e(unsigned int b)
{
    return ((b-1)*b+2)/2;
}

// Hомер первой квартиры блока
inline unsigned int f(unsigned int b)
{
    return (((2*b-3)*b+1)*b+6)/6;
}

// Hомер блока по номеру квартиры
unsigned int b(unsigned int x)
{
    unsigned int blk = exp(log(3*(x-0.99))/3.0)+2.5; // Hемного завышен
    while(x < f(blk)) blk--;
    return blk;
}

// Hомер этажа по номеру квартиры
void calc(unsigned int ap, unsigned int &flo, unsigned int &no)
{
    unsigned int blk = b(ap);
    flo = ap - f(blk);
    no = flo % blk + 1;
    flo = e(blk) + flo/blk;
}

int main()
{
    for(unsigned int ap = 1; ap <= 30; ++ap) {
        unsigned int flo, num;
        calc(ap, flo, num);
        printf("ap %10Ld: floor %4Ld, num %4Ld\n",ap,flo,num);
    }
    return 0;
}
