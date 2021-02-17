while True:
    a, b = input().split()
    if a == b == "0":
        break
    print(int(a) + int(b))