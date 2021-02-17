from collections import deque

n, m, count = int(input()), [], [0, 0, 0]

for _ in range(n):
    temp = [int(x) for x in input().split()]
    m.append(temp)

q = deque()
q.append(m)

while q:
    c = q.popleft()

    if len(set(zip([x for a in c for x in a]))) == 1:
        count[c[0][0] + 1] += 1
    elif len(c) == 3:
        for i in c:
            for x in i:
                count[x + 1] += 1
    else:
        l, result = len(c), []
        for i in range(0, l, l//3):
            for j in range(0, l, l//3):
                temp = []
                for a in c[i:i + l//3]:
                    temp.append(a[j:j + l//3])
                result.append(temp)
        q.extendleft(result)

for x in count:
    print(x)