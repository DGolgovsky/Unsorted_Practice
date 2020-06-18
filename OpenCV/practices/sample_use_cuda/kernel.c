#include <stdio.h>
#include <cuda_runtime.h>

#define SIZE 1024

__global__ void vector_add(int *a, int *b, int *c, int *n) {
	int i = threadIdx.x;
//    for (i = 0; i < n; ++i)
	if (i < n)
		c[i] = a[i] + b[i];
}

int main() {
	int *a, *b, *c;

	//a = (int *)malloc(SIZE * sizeof(int));
	cudaMallocManaged(&a, SIZE * sizeof(int));
	//b = (int *)malloc(SIZE * sizeof(int));
	cudaMallocManaged(&b, SIZE * sizeof(int));
	//c = (int *)malloc(SIZE * sizeof(int));
	cudaMallocManaged(&c, SIZE * sizeof(int));

	for (int i = 0; i < SIZE; ++i) {
		a[i] = i;
		b[i] = i;
		c[i] = 0;
	}

	vector_add<<<1, SIZE >> > (a, b, c, SIZE);

	cudaDeviceSynchronize();

	for (int i = 0; i < 10; ++i) {
		printf("c[%d] = %d\n", i, c[i]);
	}

	//free(c);
	cudaFree(c);
	//free(b);
	cudaFree(b);
	//free(a);
	cudaFree(a);

	return 0;
}
