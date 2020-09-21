int a(int i) {
	if (i > 0) {
		return a(--i);
	} else {
		return 0;
	}
}

int main() {
	return a(1);
}
