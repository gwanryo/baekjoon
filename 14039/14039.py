import sys
input = lambda: sys.stdin.readline().rstrip()
os, e = None, False

for i in range(4):
    a, b, c, d = map(int, input().split())
    if os == None:
        os = sum([a, b, c, d])
    elif os != sum([a, b, c, d]):
        e = True

print("not magic" if e else "magic")