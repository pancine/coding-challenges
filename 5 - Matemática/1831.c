//C99 23/08/2020
#include <stdio.h>
#include <stdlib.h>


struct triple{
    long long int d, x, y;
};


long long int modinv(long int, int);
struct triple MDCE(long int, int);


int main() {
	long long int total, t = 1, Nl[3];
	long int N[4];
	int s[3], c[3];

	while (scanf("%d %d %d %d %d %d", &s[0], &c[0], &s[1], &c[1], &s[2], &c[2]) != EOF) {
		total = 0;
		N[3] = c[0] * c[1] * c[2];

		for (int i = 0; i < 3; i++) {
			N[i] = N[3]/c[i];
			Nl[i] = modinv(N[i], c[i]);
			total = (total%N[3] + ((s[i]%N[3]) * (N[i]%N[3]) * (Nl[i]%N[3]))%N[3])%N[3];
		}
		
		if (total > 1) {
			printf("Caso #%lld: %lld laranja(s)\n", t++, total);
		}
		else if (total == 1) {
			printf("Caso #%lld: 1 laranja(s)\n", t++);
		}
		else {
			printf("Caso #%lld: %ld laranja(s)\n", t++, N[3]);
		}
	}

	return 0;
}


long long int modinv(long int a, int z) {
    struct triple temp = MDCE(a, z);
    return (temp.x%z + z) % z;
}


struct triple MDCE(long int a, int b) {
    struct triple temp;
    if (b == 0) {
        temp.d = a;
        temp.x = 1;
        temp.y = 0;
        return temp;
    }
    else {
        long long int x1, y1;
        temp = MDCE(b, a%b);
        x1 = temp.y;
        y1 = temp.x - (a/b) * temp.y;
        temp.x = x1;
        temp.y = y1;
        return temp;
    }
}
