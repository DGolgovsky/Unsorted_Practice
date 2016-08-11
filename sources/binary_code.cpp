#include <iostream>

#DEFINE "0000000000000001111111110001111111111100111111111110011000100011001100010001100111110111110011110001111000111111111000001010101000000110101100000011111110000000000000000" TEXT

int main(void)
{
	char greeting[] = TEXT;
	//std::cout << greeting << '\n';
	int count = 0;
	for (int j = 0; j < 13; ++j) {
		for (int i = 0; i < 13; i++) {
			if (greeting[count] == '1')
				std::cout << greeting[count];
			else
				std::cout << " ";
			count++;
		}
		std::cout << "\n";
	}
	
	return 0;
}
