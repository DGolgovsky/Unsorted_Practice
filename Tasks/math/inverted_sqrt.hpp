float inv_sqrt(float x) {
	float xhalf = 0.5f * x;
	int i = *(int *) &x;  // представим биты float в виде целого числа
	i = 0x5f3759df - (i >> 1);  // какого черта здесь происходит ?
	x = *(float *) &i;
	x = x * (1.5f - (xhalf * x * x));
	return x;
}
