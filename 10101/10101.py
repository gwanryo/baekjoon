a,b,c=int(input()),int(input()),int(input())
if a==b==c==60:
    print("Equilateral")
elif a+b+c==180 and (a==b or b==c or c==a):
    print("Isosceles")
elif a+b+c==180:
    print("Scalene")
else:
    print("Error")