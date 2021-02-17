from datetime import datetime as d
from datetime import timedelta as t
a, b = input().split()
print(d.strftime(d.strptime(a, '%Y-%m-%d') + t(days=int(b)-1), '%Y-%m-%d'))
