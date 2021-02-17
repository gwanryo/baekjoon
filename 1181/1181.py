a,n=[],int(input())
for i in range(n):
    a.append(input())
a=list(set(a))
print("\n".join(sorted(a, key=lambda x: (len(x), x))))
