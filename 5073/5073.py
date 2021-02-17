while True:
    c, b, a = sorted(list(map(int, input().split())))
    if a==b==c==0:
        break
    elif a >= b + c:
        print('Invalid')
    elif a==b==c:
        print('Equilateral')
    elif a==b or b==c or c==a:
        print('Isosceles')
    else:
        print('Scalene')