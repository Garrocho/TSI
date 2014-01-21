int soma(int a, int b) {
	if (a == 0)
		return b;
	return soma(a-1, b+1);
};

void frase_ao_contrario(char *frase, int n) {
	if (n >= 0) {
		printf("%c", frase[n]);
		return frase_ao_contrario(frase, n-1);
	}
};

int fibonacci(int n) {
	if (n < 2)
		return n;
	else 
		return fibonacci(n-1) + fibonacci(n-2);
};