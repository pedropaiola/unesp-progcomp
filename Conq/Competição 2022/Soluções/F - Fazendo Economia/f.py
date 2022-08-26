n = int(input())
a = [int(x) for x in input().split()]
p = [0]
for i in range(n):
    p.append(p[i] + a[i])
q = int(input())
for i in range(q):
    l, r = (int(x) for x in input().split())
    print(p[r]-p[l-1])