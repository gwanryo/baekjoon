n = int(input())
result = [-1 for _ in range(n + 1)]
result[n] = 0

for i in range(n, 1, -1):
    if result[i] == -1:
        continue

    if i % 3 == 0:
        if result[i // 3] == -1 or result[i // 3] > result[i] + 1:
            result[i // 3] = result[i] + 1
    
    if i % 2 == 0:
        if result[i // 2] == -1 or result[i // 2] > result[i] + 1:
            result[i // 2] = result[i] + 1

    if i - 1 >= 0:
        if result[i - 1] == -1 or result[i - 1] > result[i] + 1:
            result[i - 1] = result[i] + 1

print(result[1])