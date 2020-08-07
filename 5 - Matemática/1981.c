#include <stdio.h>
#include <string.h>

struct triple{
    long long int d, x, y;
};

long long int modinv(long long int, long long int);
struct triple MDCE(long long int, long long int);
long long int Pr(int, int *);
long long int fat(int);

int main(){
    char s[10009];
    scanf("%s", s);
    while (s[0] != '0') {
        int memory[26];
        char *p = s;
        for (int i = 0; i<=25; i++){
            memory[i] = 0;
        }
        while (*p != '\0'){
            memory[*p-97] += 1;
            p++;
        }
        printf("%lld\n",Pr(strlen(s), memory));
        scanf("%s", s);
    }
    return 0;
}

long long int modinv(long long int a, long long int z) {
    struct triple temp = MDCE(a, z);
    return (temp.x%z + z) % z;
}

struct triple MDCE(long long int a, long long int b) {
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

long long int Pr(int n, int *arraym) {
    long long int temp = fat(n);
    for (int i=0; i<26; i++) {
        if(arraym[i] > 1){
            temp = ((temp % 100000007) * modinv(fat(arraym[i]), 100000007)%100000007)%100000007;
        }   
    }
    return temp;
}

long long int fat(int n) {
    long long int total = 1;
    for (int i = 2; i <= n; i++){
        total = (total%100000007 * i%100000007)%100000007;
    }
    return total;
}