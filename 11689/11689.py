n, a, i = int(input()), [], 2
N = n
while i ** 2 <= n:
    if n % i == 0:
        while n % i == 0:
            n //= i
        N = N * (1.0 - 1.0 / float(i))
    i += 1
if n > 1:
    N = N * (1.0 - 1.0 / float(n))
print(int(N))