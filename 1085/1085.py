[x,y,w,h]=[int(x) for x in input().split(" ")]
print(min(x,w-x,y,h-y))