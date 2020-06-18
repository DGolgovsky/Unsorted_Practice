// Вернуть старшие 64 бита результата умножения двух 64-битных чисел.
inline uint64_t mul64_high(uint64_t a, uint64_t b) {
	uint64_t x0, x1, x2, x3;
	const uint64_t al = uint32_t(a), bl = uint32_t(b), ah = a >> 32, bh = b >> 32;

	x3 = al * bl;  // low
	x0 = ah * bh;  // high
	x2 = ah * bl;  // mid2
	x1 = al * bh;  // mid1

	x2 += x3 >> 32;  // no carry, max = (2**32-1)**2 + 2**32-1
	x0 += x2 >> 32;
	x1 += uint32_t(x2);  // still no carry

	return x0 + (x1 >> 32);
	//mul64_low = (x1 << 32) | uint32_t(x3); - если это кому-то интересно :)
}

// Вернуть номер старшего бита числа n (начиная с 0).
inline int bsr(uint32_t n) {
	int size = 16, shift = 8;
	uint32_t mask = 0xFFFF;
	int result = 0;

	while (n != 1) {
		uint32_t low = n >> size;
		if (low) {
			n = low;
			result += size;
		} else {
			n &= mask;
		}
		size >>= 1;
		mask >>= shift;
		shift >>= 1;
	}
	return result;
}
