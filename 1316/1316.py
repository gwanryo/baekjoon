m = n = int(input())
for i in range(n):
    a, s = [False for _ in range(26)], input()
    a[ord(s[0]) - ord('a')] = True
    for j in range(1, len(s)):
        k = ord(s[j]) - ord('a')
        if s[j - 1] != s[j] and a[k]:
            m -= 1
            break
        a[k] = True
print(m)