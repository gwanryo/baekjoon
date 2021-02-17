limit,yours=int(input()),int(input())
if limit >= yours:
    print("Congratulations, you are within the speed limit!")
elif yours - limit <= 20:
    print("You are speeding and your fine is $100.")
elif yours - limit <= 30:
    print("You are speeding and your fine is $270.")
else:
    print("You are speeding and your fine is $500.")