def c(m,i=2):
    if m == 1: return 0
    while i**2 <= m:
        if m % i == 0: return 0
        i += 1
    return 1
n,q=int(input()),0
for a in input().split(" "): q+=c(int(a))
print(q)