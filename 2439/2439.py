a = int(input())
for i in range(a):
    for j in range(a):
        if j < a - i - 1:
            print(" ", end='')
        else:
            print("*", end='')
    print('')
