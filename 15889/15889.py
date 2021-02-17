import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    n = int(input())
    distance = list(map(int, input().split()))
    power = list(map(int, input().split()))
    soldier = []

    if n == 1:
        print("권병장님, 중대장님이 찾으십니다")
        return

    for i in range(n):
        if i == n - 1:
            soldier.append((distance[i], 0))
        else:
            soldier.append((distance[i], power[i]))

    soldier = sorted(soldier, key=lambda x: x[0])
    available = [False for _ in range(n)]
    available[0] = True

    for i in range(n - 1):
        if not available[i]:
            continue

        temp = i + 1

        while temp < n:
            if soldier[i][0] + soldier[i][1] >= soldier[temp][0]:
                available[temp] = True
            else:
                break

            temp += 1

    print(["엄마 나 전역 늦어질 것 같아", "권병장님, 중대장님이 찾으십니다"][available[n - 1]])

main()
