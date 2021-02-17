n = int(input())
for _ in range(n):
    quiz, score = [len(x) for x in input().split("X") if len(x) > 0], 0
    for q in quiz:
        score += (q * q + q) // 2
    print(score)