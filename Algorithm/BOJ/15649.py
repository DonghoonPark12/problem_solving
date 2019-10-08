a, b = map(int, input().split())
l=[]
p=[]
for i in range(a):
    l.append(i+1)

def rec(n):
    if len(p) == b:
        for i in range(b):
            print(i)
    p.append(l[n])
    rec(n+1)
    p.pop()
rec(0)