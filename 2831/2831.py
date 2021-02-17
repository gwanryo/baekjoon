import heapq
import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())

men_taller, men_shorter = [], []
women_taller, women_shorter = [], []

for man in input().split():
    man = int(man)
    if man > 0:
        heapq.heappush(men_taller, man)
    else:
        heapq.heappush(men_shorter, -man)

for woman in input().split():
    woman = int(woman)
    if woman > 0:
        heapq.heappush(women_taller, woman)
    else:
        heapq.heappush(women_shorter, -woman)

def matching(a, b):
    success = 0

    while a and b:
        cur_a, cur_b = a[0], heapq.heappop(b)

        if cur_a < cur_b:
            success += 1
            heapq.heappop(a)

    return success

print(matching(men_taller, women_shorter) + matching(women_taller, men_shorter))