n = int(input())
m = []
for i in range(n):
    k = input().split()
    m.append((int(k[0]), k[1:]))
m = sorted(m, key = lambda x: x[0])
for mm in m:
    print(f"{mm[0]} {''.join(mm[1])}")