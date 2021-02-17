a = int(input())
print(0 if a%4 != 0 else 1 if a%100 != 0 or a%400 == 0 else 0)