import sys
input=lambda:sys.stdin.readline().rstrip()
a='abcdefghijklmnopqrstuvwxyz'
s=input()
dic={c:[0 for _ in s] for c in a}
for i, c in enumerate(s):
 dic[c][i]=1
for i in a:
 for j in range(1, len(s)):
  dic[i][j]+=dic[i][j - 1]
for _ in range(int(input())):
 c,s,e=input().split()
 print(dic[c][int(e)]-(0 if s=='0' else dic[c][int(s)-1]))
