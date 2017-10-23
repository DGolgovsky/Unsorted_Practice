#include <iostream>
#include <cmath>

// Hомер первого этажа по номеру блока
uint e(uint b)
{
    return ((b - 1) * b + 2) / 2;
}

// Hомер первой квартиры блока
inline uint f(uint b)
{
    return (((2*b - 3) * b + 1) * b  + 6) / 6;
}

// Hомер блока по номеру квартиры
uint b(uint x)
{
    uint blk = exp(log(3 * (x-0.99)) / 3.0) + 2.5; // Hемного завышен
    while(x < f(blk))
		blk--;
    return blk;
}

// Hомер этажа по номеру квартиры
void calc(uint ap, uint &flo, uint &no)
{
    uint blk = b(ap);
    flo = ap - f(blk);
    no = flo % blk + 1;
    flo = e(blk) + flo/blk;
}

int main()
{
	uint ap = 0;
	uint flo, num;
	std::cin >> ap;
    calc(ap, flo, num);
	std::cout << flo << " " << num << '\n';
    
    return 0;
}
