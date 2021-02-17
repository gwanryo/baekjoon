import sys
input = lambda: sys.stdin.readline().rstrip()
n = int(input())
time = []
for i in range(n):
    a, b = map(int, input().split())
    time.append(a - b)
time.sort()
if len(time) % 2:
    print(1)
else:
    print(abs(time[n // 2] - time[n // 2 - 1]) + 1)