#include <iostream>

void swapr (int &a, int &b);
void swapp (int *p, int *q);
void swapv (int a, int b);
void print_result (int a, int b);

using namespace std;

int main() {	
	int wallet1 = 300;
	int wallet2 = 350;
	
	cout << "Using references to swap contents:\n";
	swapr(wallet1, wallet2);
	print_result(wallet1, wallet2);
	
	cout << "Using pointers to swap contents again:\n";
	swapp(&wallet1, &wallet2);
	print_result(wallet1, wallet2);
	
	cout << "Trying to use passing by value:\n";
	swapv(wallet1, wallet2);
	print_result(wallet1, wallet2);
	cin.get();
	return 0;
}

void print_result (int a, int b) {
	cout << "wallet1 = $" << a
		 << " wallet2 = $" << b << endl;
}

void swapr (int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp (int *p, int *q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv (int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
