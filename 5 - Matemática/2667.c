#include <stdio.h>
#include <string.h>

int main() {
	long long int total = 0;
	char n[101];
	scanf("%s", &n);

	for (char *i = n; *i != '\0'; i++) {
		total += (*i - 48);
	}
	printf("%lld\n", total%3);
	
	return 0;
}