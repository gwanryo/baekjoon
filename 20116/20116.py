import sys
input = lambda: sys.stdin.readline().rstrip()

n, L = map(int, input().split())
xa = []

for i in input().split():
    xa.append(int(i))

prev_x = 0
for i, x in enumerate(xa[::-1]):
    if i == 0:
        prev_x = x
        continue

    if prev_x < x + L and prev_x > x - L:
        prev_x = ((prev_x * i) + x) / (i + 1)
    else:
        print("unstable")
        exit()

print("stable")