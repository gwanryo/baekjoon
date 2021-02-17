a=[int(input()) for _ in [0]*5]
print(sum(40 if x < 40 else x for x in a)//5)