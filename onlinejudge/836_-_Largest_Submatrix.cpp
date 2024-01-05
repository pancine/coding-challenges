#include <string.h>

#include <iostream>
using namespace std;

int matrix[30][30];

int calculate_submatrix(int n);

int main() {
    string matrix_input;
    int test_cases, matrix_order;

    cin >> test_cases;

    while (test_cases-- > 0) {
        memset(matrix, 0, sizeof(matrix));

        cin >> matrix_input;
        matrix_order = matrix_input.length();

        for (int i = 1; i <= matrix_order; i++) {
            matrix[1][i] = matrix_input[i - 1] - '0';
        }

        for (int i = 2; i <= matrix_order; i++) {
            cin >> matrix_input;

            for (int j = 1; j <= matrix_order; j++) {
                matrix[i][j] = matrix_input[j - 1] - '0';
            }
        }

        calculate_submatrix(matrix_order);
        if (test_cases > 0)
        {
            cout << endl;
        }
        
    }

    return 0;
}

int calculate_submatrix(int n) {
    int sum[30][30];
    int max_sum = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] == 0) matrix[i][j] = -1000;
            sum[i][j] = matrix[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int p = i; p <= n; p++) {
                for (int q = j; q <= n; q++) {
                    int t = sum[p][q] - sum[p][j - 1] - sum[i - 1][q] + sum[i - 1][j - 1];
                    max_sum = max(t, max_sum);
                }
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}