n, m = input().split()
n, m = int(''.join(reversed(n))), int(''.join(reversed(m)))
print(n if n > m else m)