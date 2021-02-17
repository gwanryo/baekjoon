from collections import deque as d
import sys
input = lambda: sys.stdin.readline().rstrip()

n = int(input())
deque = d()
for _ in range(n):
    cmd = input()

    if " " in cmd:
        cmd, m = cmd.split()

    if cmd == "push_front":
        deque.appendleft(m)
    
    if cmd == "push_back":
        deque.append(m)

    if cmd == "pop_front":
        if len(deque):
            print(deque.popleft())
        else:
            print(-1)

    if cmd == "pop_back":
        if len(deque):
            print(deque.pop())
        else:
            print(-1)

    if cmd == "size":
        print(len(deque))

    if cmd == "empty":
        print(1 if len(deque) == 0 else 0)

    if cmd == "front":
        if len(deque):
            print(deque[0])
        else:
            print(-1)

    if cmd == "back":
        if len(deque):
            print(deque[-1])
        else:
            print(-1)