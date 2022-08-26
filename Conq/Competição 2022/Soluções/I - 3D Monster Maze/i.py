lab = []
mov = [(0,1), (0,-1), (1, 0), (-1, 0)]

def movimentar(pos, sentido):
    newPos = [pos[0], pos[1]]
    newPos[0] += mov[sentido][0]
    newPos[1] += mov[sentido][1]
    return newPos

def ehValida(pos):
    global lab
    if pos[0] < 0 or pos[0] >= n or pos[1] < 0 or pos[1] >= n:
        return False
    return lab[pos[0]][pos[1]] == '.' or lab[pos[0]][pos[1]] == 'S'

def printLab(omitirParedes=True):
    global lab
    for i in range(n):
        for j in range(n):
            if omitirParedes and lab[i][j] == '#':
                print('.', sep='', end='')
            else:
                print(lab[i][j], sep='', end='')
        print('')

def percorrerLab(pos):
    global lab
    #printLab(omitirParedes=False)
    for sentido in range(4):
        newPos = movimentar(pos, sentido)
        if not ehValida(newPos):
            continue
        if lab[newPos[0]][newPos[1]] == 'S':
            #printLab(omitirParedes=False)
            return True
        lab[newPos[0]][newPos[1]] = 'C'
        if percorrerLab(newPos):
            return True
        lab[newPos[0]][newPos[1]] = '.'
    return False



n = int(input()) + 2
for i in range(n):
    entrada = input()
    lab.append([x for x in entrada])
    for j in range(n):
        if lab[i][j] == 'I':
            ini = [i, j]
percorrerLab(ini)
printLab()