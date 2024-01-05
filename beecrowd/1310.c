//C99 07/09/2020
#include <stdio.h>

int SCSM(int dias, int cd, int *r);

int main() {
	int dias, custo_dia, receita[50], soma = 0;
	while (scanf("%d", &dias) != EOF) {
		scanf("%d", &custo_dia);
		for (int i = 0; i < dias; i++) 
			scanf("%d", &receita[i]);

		soma = SCSM(dias, custo_dia, receita);
		printf("%d\n", soma);
	}
	return 0;
}

int SCSM(int dias, int cd, int *r) {
	int sm = 0, im = 0, fm = 0, ss = 0, is = 0, fs = 0;

	for (int i = 0; i < dias; i++) {
		if (ss + (r[i] - cd) >= 0) {
			ss += (r[i] - cd);
			fs = i;
			if (is = 0) {
				is = i;
			}
			if (ss > sm) {
				sm = ss; im = is; fm = fs;
			}
		}
		else {
			ss = 0; is = 0; fs = 0;
		}
	}
	
	return sm;
}