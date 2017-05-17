#include <stdio.h>

void foo(void);
void bar(void);
void print_function_instructions(void *func_ptr, size_t func_len);

int main(void) {
	void *foo_addr = (void*)foo;
	void *bar_addr = (void*)bar;

	print_function_instructions(foo_addr, bar_addr - foo_addr);

	return 0;
}

void foo(void) {
	int i = 0;
	i++;
	printf("i: %d\n", i);
}

void bar(void) {}

void print_function_instructions(void *func_ptr, size_t func_len) {
	unsigned char i = 0;
	for (i; i < func_len; i++) {
		unsigned char *instruction = (unsigned char*)func_ptr + i;
		printf("%p (%2u): %x\n", func_ptr + i, i, *instruction);
	}
}

