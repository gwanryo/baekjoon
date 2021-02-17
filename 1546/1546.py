n, a = int(input()), [int(x) for x in input().split()]
b = [x * 100 / max(a) for x in a]
print(sum(b) / len(b))