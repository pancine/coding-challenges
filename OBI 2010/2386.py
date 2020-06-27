# Python 3.4.3 25/06/2020
A = int(input())
N = int(input())
cont = 0

for x in range(N):
    num = int(input())
    if (num * A >= 4 * 10**7):
        cont += 1
print(cont)
