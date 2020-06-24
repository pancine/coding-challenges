#Python 3.4.3 24/06/2020
n = int(input())
d = 0

for x in range(n):
	s = input()
	s = s.split(' ')
	t, v = int(s[0]), int(s[1])
	d += (t * v)

print(d)