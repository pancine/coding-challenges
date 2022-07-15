n = int(input())

V = list(map(int, input().split()))

result = 1

D = [1] * n

for i in range(n-2, -1, -1):
    if V[i+1] > V[i]:
        D[i] = D[i+1] + 1
    result = max(result, D[i])

E = [1] * n

for i in range(1, n):
    if V[i-1] < V[i]:
        E[i] = E[i-1] + 1
    result = max(result, E[i])

for i in range(n-2):
    if V[i] < V[i+2]:
        result = max(result, E[i] + D[i+2])

print(result)
