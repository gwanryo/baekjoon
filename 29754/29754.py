# Kizuna Ai, Omaru Polka, Ange Katrina, Nekota Tsuna, KMNZ LITA

import sys
input = lambda: sys.stdin.readline().rstrip()

schedules = {}
n, m = map(int, input().split())
for _ in range(n):
    name, day, haisin_start, haisin_end = input().split()
    week = (int(day) - 1) // 7
    start_hour, start_minute = map(int, haisin_start.split(":"))
    end_hour, end_minute = map(int, haisin_end.split(":"))
    if name not in schedules:
        schedules.setdefault(name, [])
        for _ in range(m // 7):
            schedules[name].append([])
    schedules[name][week].append((end_hour - start_hour) * 60 + end_minute - start_minute)

haisin = {}
for name, weektimes in schedules.items():
    for times in weektimes:
        if len(times) >= 5 and sum(times) >= 60 * 60:
            if name not in haisin:
                haisin.setdefault(name, 0)
            haisin[name] += 1

honmono = [name for name, count in haisin.items() if count == m // 7]
if len(honmono) == 0:
    print(-1)
else:
    print(*sorted(honmono), sep="\n")