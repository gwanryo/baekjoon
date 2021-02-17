a, _, i, r = "IO" * int(input()) + "I", input(), 0, 0
for j, c in enumerate(input()):
    if a[i] != c:
        i = 0
    if a[i] == c:
        i += 1
        if i == len(a):
            r += 1
            i -= 2
print(r)