import sys
input = lambda: sys.stdin.readline().rstrip()
n, q = map(int, input().split())
b, b_t = [], 0
t, t_s = [], []
result = {}

for i in range(n):
    b_t += int(input())
    b.append(b_t)

for i in range(q):
    t.append(int(input()))

t_s = sorted(t)
b_i, t_i = 0, 0

while t_i < len(t_s):
    if b[b_i] > t_s[t_i]:
        result.setdefault(t_s[t_i], b_i + 1)
        t_i += 1
    else:
        b_i += 1

for t_m in t:
    print(result[t_m])
