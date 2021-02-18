n = int(input())
q = []
for _ in range(n):
    a, b = map(int, input().split())
    q.append([a, b, 1])

for i, t in enumerate(q):
    for j, m in enumerate(q):
        if i == j:
            continue

        if t[0] < m[0] and t[1] < m[1]:
            t[2] += 1

print(' '.join([str(m[2]) for m in q]))