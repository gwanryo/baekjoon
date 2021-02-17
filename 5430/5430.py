import sys
input = lambda: sys.stdin.readline().rstrip()
for _ in range(int(input())):
    f, n = input(), int(input())
    a = eval(input())

    d = f.count("D")
    r = len(f) - d

    if d > len(a):
        print("error")
        continue

    if d == len(a):
        print("[]")
        continue

    i = 0
    for c in f:
        if c == "R":
            i = -1 - i
        elif c == "D":
            del a[i]

    if r % 2:
        a.reverse()

    print('[' + (','.join([str(x) for x in a])) + ']')
