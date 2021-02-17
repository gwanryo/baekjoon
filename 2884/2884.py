import datetime as d
dt = d.datetime.strptime(input(),'%H %M') - d.timedelta(minutes=45)
h, m = d.datetime.strftime(dt, "%H"), d.datetime.strftime(dt, "%M")
print("0" if h == "00" else h.lstrip("0"), "0" if m == "00" else m.lstrip("0"))
