a, b, c = map(int,input().split())
x1, x2, y1, y2 = map(int,input().split())

def onEdge(x, y):
    global a, b, c
    return True if a * x + b * y + c == 0 else False

def onLine(x1, y1, x2, y2):
    global a, b, c
    result = (a * x1 + b * y1 + c) * (a * x2 + b * y2 + c)
    return True if result < 0 else False

if onEdge(x1, y1) or onEdge(x1, y2) or onEdge(x2, y1) or onEdge(x2, y2):
    print("Lucky")
elif onLine(x1, y1, x1, y2) or onLine(x1, y2, x2, y2) or onLine(x2, y2, x2, y1) or onLine(x2, y1, x1, y1):
    print("Poor")
else:
    print("Lucky")