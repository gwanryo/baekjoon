from functools import cmp_to_key
import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
s = [input() for i in range(n)]

INDEX = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"

def cmp_items(a, b):
    x, y = 0, 0
    while x < len(a) and y < len(b):
        if a[x].isalpha() and b[y].isdigit():
            return 1
        elif a[x].isdigit() and b[y].isalpha():
            return -1
        elif a[x].isdigit() and b[y].isdigit():
            start_x = x
            while x < len(a) and a[x].isdigit():
                x += 1
            num_x = a[start_x:x]

            start_y = y
            while y < len(b) and b[y].isdigit():
                y += 1
            num_y = b[start_y:y]

            if int(num_x) > int(num_y):
                return 1
            elif int(num_x) == int(num_y):
                if len(num_x) != len(num_y):
                    return len(num_x) - len(num_y)
                else:
                    continue
            else:
                return -1
        else:
            x_loc = INDEX.index(a[x])
            y_loc = INDEX.index(b[y])

            if x_loc > y_loc:
                return 1
            elif x_loc < y_loc:
                return -1

            x += 1
            y += 1
    return len(a) - len(b)

c = cmp_to_key(cmp_items)

for res in sorted(s, key=c):
    print(res)
