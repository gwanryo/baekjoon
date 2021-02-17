n, k = map(int, input().split())
money, t = [int(input()) for _ in [0] * n][::-1], 0
for cost in money:
    if cost <= k:
        t += k // cost
        k -= cost * (k // cost)
print(t)