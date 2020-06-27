# Python 3.4.3 27/06/2020
def nextr(str, pos):
    while str[pos] != 'R':
        pos += 1

    return pos

def verify(str, pos, side, seek):
    cont, add = 0, 1
    if side == 'E':
        add = -1

    while (0 <= pos < len(str)) and (str[pos] != seek):
        cont += 1
        pos += add

    if pos < 0 or pos == len(str):
        pos -= add

    if str[pos] == seek:
        return (1, cont)

    return (0, -1)

def dist(str, pos, side, seek):
    i = 1
    if side == 'E':
        i = -1

    flag = [0, 0, 0]
    dist = [0, 0, 0]
    flag[0], dist[0] = verify(str, pos, side, seek)

    if flag[0] == 0:
        return -1

    if seek == 'C':
        flag[1], dist[1] = verify(str, pos + (i * dist[0]), 'E', 'F')
        flag[2], dist[2] = verify(str, pos + (i * dist[0]), 'D', 'F')

    else:
        flag[1], dist[1] = verify(str, pos + (i * dist[0]), 'E', 'C')
        flag[2], dist[2] = verify(str, pos + (i * dist[0]), 'D', 'C')

    if flag[1] and flag[2]:
        if (dist[0] + dist[1]) > (dist[0] + dist[2]):
            return dist[0] + dist[2]
        else:
            return dist[0] + dist[1]

    elif flag[1] == 0:
        return dist[0] + dist[2]

    else:
        return dist[0] + dist[1]

n = int(input())
flush = input()
posr = 0

for x in range(n):
    d = [0, 0, 0, 0, 1000001]
    str = input()
    str = list(str)
    flush = input()

    while('R' in str):
        posr = nextr(str, 0)
        str[posr] = '.'
        d[0] = dist(str, posr, 'E', 'C')
        d[1] = dist(str, posr, 'D', 'C')
        d[2] = dist(str, posr, 'E', 'F')
        d[3] = dist(str, posr, 'D', 'F')
        for x in range(4):
            if d[x] > 0 and d[x] < d[4]:
                d[4] = d[x]

    print("%d\n" % (d[4]))