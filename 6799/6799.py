import sys
input = lambda: sys.stdin.readline().rstrip()

rank, n = [], int(input())

for i in range(n):
    name, r, s, d = input().split()
    r, s, d = int(r), int(s), int(d)
    score = 2 * r + 3 * s + d
    rank.append((name, -score))

rank.sort(key = lambda x: (x[1], x[0]))

if len(rank) >= 2:
    print(rank[0][0])
    print(rank[1][0])
elif len(rank) == 1:
    print(rank[0][0])