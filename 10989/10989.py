import sys
input = lambda: sys.stdin.readline().rstrip()
q=[0 for _ in range(10001)]
for _ in range(int(input())):
    q[int(input())] += 1
for i in range(1, 10001):
    for j in range(q[i]):
        print(i)