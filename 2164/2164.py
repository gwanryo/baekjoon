import math
n=int(input())
print(2*n-2**(int(math.log(n - 1, 2)) + 1) if n!=1 else 1)