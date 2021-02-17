a, b, c = (int(input()) for _ in range(3))
s, t = a * b * c, [0 for i in range(10)]
while s != 0:
    s, m = s // 10, s % 10
    t[m] += 1
print('\n'.join([str(x) for x in t]))
