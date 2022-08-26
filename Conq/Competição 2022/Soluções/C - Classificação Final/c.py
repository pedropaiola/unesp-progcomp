import functools

def compara(a, b):
    if a[2] < b[2]:
        return 1
    elif a[2] > b[2]:
        return -1
    elif a[1] < b[1]:
        return -1
    elif a[1] > b[1]:
        return 1
    elif a[3] < b[3]:
        return 1
    return -1


n = int(input())
placar = []
for i in range(n):
    competidor, pais, pontos = input().split()
    pontos = int(pontos)
    placar.append((competidor, pais, pontos, i))
placar = sorted(placar, key=functools.cmp_to_key(compara))

premios = [placar[0]]
achousegundolugar = False

for i in range(n):
    if (placar[i][1] != premios[0][1]) and not achousegundolugar:
        premios.append(placar[i])
        achousegundolugar = True
    elif (placar[i][1] != premios[0][1]) and (placar[i][1] != premios[1][1]):
        premios.append(placar[i])
        break

print(len(premios))
for i in range(len(premios)):
    print(i+1, premios[i][1],premios[i][0])