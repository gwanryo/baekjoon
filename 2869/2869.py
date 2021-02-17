import math
u, d, l = (int(x) for x in input().split())
print(math.ceil((l - d) / (u - d)))