from datetime import datetime
for _ in [0]*3:
    a = input().split()
    s, e = ' '.join(a[:3]), ' '.join(a[3:])
    s = datetime.strptime(s, "%H %M %S")
    e = datetime.strptime(e, "%H %M %S")
    diff = (e - s).seconds
    print(f"{diff // 3600} {(diff % 3600) // 60} {(diff % 3600) % 60}")
