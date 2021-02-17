minN, minM = 8, 8

def color(map, x, y, bw = 0):
    count = 0
    global minN, minM
    for i in range(x, x + minN):
        for j in range(y, y + minM):
            if map[i][j] != bw:
                count += 1
            bw = 1 - bw
        bw = 1 - bw
    return count

n, m = tuple([int(x) for x in input().split(" ")])
map = []
for i in range(n):
    s, tmp = input(), []
    for sm in s:
        if sm == "W":
            tmp.append(0)
        else:
            tmp.append(1)
    map.append(tmp)

minCount = n * m + 1
for i in range(n - minN + 1):
    for j in range(m - minM + 1):
        #print(f"{i}, {j} - W {color(map, i, j, 0)}, B {color(map, i, j, 1)}")
        tempCount = min(color(map, i, j, 0), color(map, i, j, 1))
        if minCount > tempCount:
            minCount = tempCount

print(minCount)