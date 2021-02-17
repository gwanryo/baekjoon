s = {}
for i in range(10):
    n = int(input())
    s.setdefault(n % 42, 0)
print(len(s.keys()))
