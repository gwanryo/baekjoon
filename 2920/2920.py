a = input().split(" ")
if "".join(sorted(a)) == "".join(a):
	print("ascending")
elif "".join(sorted(a, reverse=True)) == "".join(a):
	print("descending")
else:
	print("mixed")