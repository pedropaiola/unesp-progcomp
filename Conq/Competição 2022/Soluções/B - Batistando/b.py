def consegueComprar(lojas, x):
    resp = 0
    for c in lojas:
        if c <= x:
            x -= c
            resp += 1
    return resp

n, k = [int(x) for x in input().split()]
lojas = [int(x) for x in input().split()]
soma = sum(lojas)
for x in range(1,soma+1):
    if consegueComprar(lojas, x) >= k:
        print(x)
        break