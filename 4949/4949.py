a = ''
while a != '.':
    a, q = input(), []

    if a == '.':
        break

    for c in a:
        if c == '(':
            q.append('(')
        if c == '[':
            q.append('[')
        
        if c == ')' or c == ']':
            if len(q) == 0:
                print('no')
                break

            if c == ')' and q[-1] != '(':
                print('no')
                break

            if c == ']' and q[-1] != '[':
                print('no')
                break

            del q[-1]
    else:
        if len(q) == 0:
            print('yes')
        else:
            print('no')
