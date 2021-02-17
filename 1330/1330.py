a, b = input().split()
a, b = int(a), int(b)
print("<" if a < b else ">" if a > b else "==")