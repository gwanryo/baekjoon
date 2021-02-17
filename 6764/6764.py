a = [int(input()) for _ in [0]*4]
b = [a[i] - a[i - 1] for i in range(1, len(a))]
c = 1 if b[0] > 0 else -1 if b[0] < 0 else 0
for i in b:
    if c == 1 and i > 0:
        pass
    elif c == -1 and i < 0:
        pass
    elif c == 0 and i == 0:
        pass
    else:
        print("No Fish")
        exit()
print("Fish Rising" if c == 1 else "Fish Diving" if c == -1 else "Fish At Constant Depth")
