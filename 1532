//C99 20/03/2020
#include <stdio.h>
#include <math.h>

int check(int , int);
int val_repeat(int);

int main(){
	int nb, vel, pos = 0, sv, flag = 0, j;
	int i = 0;
	scanf("%d %d", &nb, &vel);
	while (nb != 0 || vel != 0){
		sv = vel;
		for (i = 0; i < sv; ++i){
			vel = sv - i;
			while (vel > 0){
				for (j = 0; j < vel; j++){
					pos += vel;
					flag = check(pos, nb);
					if (flag == 1) break;
				}
				vel--;
				if (flag == 1) break;
			}
			if (flag == 1){
				printf("possivel\n");
				break;
			}
			pos = 0;
		}
		if (flag == 0){
			printf("impossivel\n");
		}
		scanf("%d %d", &nb, &vel);
		pos = 0;
		flag = 0;
	}
	return 0;
}

int check(int p, int n){
	if (p == n)
		return 1;
	else
		return 0;
}
