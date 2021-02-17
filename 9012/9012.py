n, v = int(input()), 0
for i in range(n):
    case = input()
    for c in case:
        if v < 0:
            break

        if c == "(":
            v += 1
        elif c == ")":
            v -= 1

    if v == 0:
        print("YES")
    else:
        print("NO")

    v = 0