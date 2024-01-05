from re import S


S = [[]] 
C = [[]]

rows_in_the_stack = int(input())
i = 1
for l in range(i):
    for j in range(i):
        print()

S[i, j] = max(S[i-1, j] + C[i, j], S[i, j+1])