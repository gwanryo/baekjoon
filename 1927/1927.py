import heapq
import sys
input = lambda: sys.stdin.readline().rstrip()
heap = []
for i in range(int(input())):
    n = int(input())
    if n == 0:
        print(heapq.heappop(heap) if len(heap) else 0)
    else:
        heapq.heappush(heap, n)
