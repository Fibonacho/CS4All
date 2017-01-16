int main() {

	int* a;
	int* b;
	int* c;

	write(1, "1", 1);
	a = malloc(1);

	write(1, "2", 1);
	b = malloc(10);

	write(1, "3", 1);
	c = malloc(100);

	free(a);
	free(c);
	free(b);

}
