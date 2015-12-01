#include <stdio.h>
#include "header.h"

int main(int argc, char* argv[])
{
	float d = 2;
	printf("CalcCirc = %f\n", CalcCirc1(d));
	printf("CalcCirc = %f\n", CalcCirc2(d));
	printf("CalcCirc = %f\n", CalcCirc3(d));
	printf("CalcCirc = %f\n", CalcCirc4(d));
	return 0;
}
