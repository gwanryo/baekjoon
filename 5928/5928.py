from datetime import datetime
s=datetime.strptime("2011-11-11 11 11","%Y-%m-%d %H %M")
e=datetime.strptime(f"2011-11-{input()}","%Y-%m-%d %H %M")
if e < s:
    print(-1)
else:
    print((e - s).days * 24 * 60 + (e - s).seconds // 60)