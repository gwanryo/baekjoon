a,b,c,d,p=[int(input()) for _ in [0] * 5]
print(min(a*p, b+(0 if p<c else d*(p-c))))