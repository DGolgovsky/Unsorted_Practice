#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main(int argc, char** argv)
{
	char str[100];
	scanf("%s", str);
	for (int i = 0; i < 100; ++i)
		if (str[i] == '.' || str[i] == ',') {
			printf("%s\n", "0");
		    return EXIT_SUCCESS;
		}

    long long int number, result = 0;
  
    number = atoll(str);
  
    for (; number > 0; ++result) number -= result;
    printf("%lld\n", result ? result - 1 : 0);

    return EXIT_SUCCESS;
}
