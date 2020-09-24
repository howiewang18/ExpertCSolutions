int main() {
	int c[1001] = {1};
	int d[1001] = {0};
	#ifdef UNALIGNED
	int *a = (int*)((char*)c + 1);
	int *b = (int*)((char*)d + 1);
	#else
	int *a = c;
	int *b = d;
	#endif
	for (int j = 0; j < 100000000; ++j) {
		for (int i = 0; i < 1000; ++i) {
			b[i] += a[i];
		}
	}
	return 0;
}
