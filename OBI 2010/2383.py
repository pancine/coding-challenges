# Python 3.4.3 24/06/2020
from math import ceil

s = input()
s = s.split(' ')
N, M = int(s[0]), int(s[1])
MAX = N
cont = 0
if M == 1:
    print(N)
else:
    N = ceil(N / 2)
    M -= 1
    cont += 1

    if (MAX - N) < N:
        while M > 1 and N < MAX:
            N = N + ceil((MAX - N) / 2)
            M -= 1
            cont += 1
        if M == 1 and N < MAX:
            cont += (MAX - N)
    else:
        while M > 1 and N > 1:
            N = ceil(N / 2)
            M -= 1
            cont += 1
        if M == 1 and N > 1:
            N = ceil(N / 2)
            cont += N
    print(cont)
