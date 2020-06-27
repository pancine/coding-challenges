# Python 3.4.3 25/06/2020
a = int(input())
copos = 0

for x in range(a):
    s = input()
    s = s.split(' ')
    L, C = int(s[0]), int(s[1])
    if L > C:
        copos += C

print(copos)
