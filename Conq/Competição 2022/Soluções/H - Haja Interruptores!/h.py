def resolver(lampAcesas, interruptores, qtdeLampAcesas):
    qtdeInt = len(interruptores)
    qtdeLamp = len(lampAcesas)
    qtdeLampApagadas = qtdeLamp - qtdeLampAcesas

    if qtdeLampApagadas == qtdeLamp:
        return 0

    mov = 0
    for k in range(2):
        for i in range(qtdeInt):
            mov += 1
            for pos in interruptores[i]:
                lampAcesas[pos] = not lampAcesas[pos]
                if lampAcesas[pos]:
                    qtdeLampApagadas -= 1
                else:
                    qtdeLampApagadas += 1
            if qtdeLampApagadas == qtdeLamp:
                return mov
    return -1

qtdeInt, qtdeLamp = [int(x) for x in input().split()]

entrada = [int(x) for x in input().split()]
qtdeLampAcesas = entrada[0]
lampAcesa = [False for x in range(qtdeLamp)]
for i in range(qtdeLampAcesas):
    lampAcesa[entrada[i+1]-1] = True

interruptores = []
for i in range(qtdeInt):
    entrada = [int(x)-1 for x in input().split()]
    interruptores.append(entrada[1:])
print(resolver(lampAcesa, interruptores, qtdeLampAcesas))