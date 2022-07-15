MOD = 1000007

R = [0] * 10001
T = [0] * 10001

test_cases = int(input())

R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7] = 0, 0, 1, 1, 2, 5, 7, 12

for i in range(8, 10001):
    R[i] = R[i-2] + R[i-3] + R[i-4] + (3*R[i-5]) + (3*R[i-6]) + R[i-7]
for i in range(8):
    T[i] = R[i]
for i in range(8, 10001):
    T[i] = (R[i] - R[i - 6]) % MOD

for i in range(test_cases):
    toothpicks = int(input())
    print(T[toothpicks])
