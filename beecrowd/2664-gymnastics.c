#include <stdio.h>

long long int T[100002][51];

int main()
{
    int t, m, n, i, j;
    long long int sum = 0;
    scanf("%d %d %d", &t, &m, &n);
    
    for (j = 1; j <= 50; j++)
    {
        for (i = 1; i <= 100000; i++)
        {
            if (j == 1 && i >= m && i <= n)
            {
                T[i][j] = 1;
            }
            else if (i < m || i > n)
            {
                T[i][j] = 0;
            }
            else if (j > 1 && i >= m && i <= n)
            {
                T[i][j] = T[i-1][j-1] + T[i+1][j-1];
            }
        } 
    }

    for (i = m; i <= n; i++)
    {
        sum = (sum%1000000007 + T[i][t]%1000000007)%1000000007;
    }

    printf("%lld\n", sum);

    return 0;
}