import statistics
import sys
input = lambda: sys.stdin.readline().rstrip()
n, a = int(input()), []
for _ in range(n):
    a.append(int(input()))
print(round(sum(a) / n))
a.sort()
print(a[n // 2])
b = sorted(statistics.multimode(a))
if len(b) == 1:
    print(b[0])
else:
    print(b[1])
print(max(a) - min(a))