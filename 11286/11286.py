import heapq
import sys
input = lambda: sys.stdin.readline().rstrip()
lo_heap, hi_heap = [], []
for i in range(int(input())):
    n = int(input())
    if n < 0:
        heapq.heappush(lo_heap, -n)
    elif n > 0:
        heapq.heappush(hi_heap, n)
    else:
        lo = heapq.heappop(lo_heap) if len(lo_heap) else 2**31+1
        hi = heapq.heappop(hi_heap) if len(hi_heap) else 2**31+1

        if hi >= lo:
            if lo == 2**31+1:
                print(0)
            else:
                print(-lo)

            if hi:
                heapq.heappush(hi_heap, hi)
        
        if hi < lo:
            if hi == 2**31+1:
                print(0)
            else:
                print(hi)

            if lo:
                heapq.heappush(lo_heap, lo)
