a, c = int(input()), 0
for i in range(0, a + 1, 5):
    j = i
    while j and j % 5 == 0:
        c += 1
        j //= 5
print(c)