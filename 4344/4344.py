n = int(input())
for _ in range(n):
    score = [int(x) for x in input().split()]
    avg = sum(score[1:]) / score[0]
    print(f"{len([x for x in score[1:] if x > avg]) * 100 / score[0]:.3f}%")