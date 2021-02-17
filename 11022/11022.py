import sys
a = int(input())
for i in range(a):
    x, y = sys.stdin.readline().rstrip().split()
    x, y = int(x), int(y)
    print(f"Case #{i + 1}: {x} + {y} = {x + y}")