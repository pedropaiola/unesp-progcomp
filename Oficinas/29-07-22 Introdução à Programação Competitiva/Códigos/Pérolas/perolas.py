while True:
    p, a, r = (int(x) for x in input().split()) #uma forma de ler três inteiro em uma única linha, já convertendo de string para int
    if a == 0: #Loop encerrado qdo p == a == r == 0 (nesse caso só precisa testar um deles)
        break
    maxPerolas = 0
    perolas = set() #conjunto que armazena as pérolas listadas pelo professor
    nomes = set()   #conjunto dos nomes que cometeram mais pérolas
    for i in range(p):
        resp = input()      #Lendo as pérolas
        perolas.add(resp)   #Inserindo as pérolas em um conjunto
    
    #Lendo os nomes dos alunos
    for i in range(a):
        nome = input()
        qtdePerolas = 0

        #Lendo cada uma das respostas de um aluno
        for j in range(r):
            resp = input()
            if resp in perolas:     #Verificando se a resposta é uma pérola 
                qtdePerolas += 1    #Se sim, incrementamos a quantidade de pérolas    

        if qtdePerolas > maxPerolas:    #Se esse é o aluno que mais cometeu pérolas até o momento
            nomes = set()               #Limpamos o conjunto com nomes dos alunos com mais pérolas 
            nomes.add(nome)             #inserimos o nome deste aluno
            maxPerolas = qtdePerolas    #e alteramos o número máximo de pérolas
        elif qtdePerolas == maxPerolas: #Se esse aluno empatou com quem cometeu mais pérolas até o momento
            nomes.add(nome)             #inserimos ele no conjunto também
    
    nomes = sorted(list(nomes)) #transformando o conjunto "nomes" em uma lista e ordenando ela (para a impressão)
    #Imprimindo o nome dos alunos que cometeram mais pérolas
    for it in nomes:    #for-each: para cada valor (it) dentro da list (nomes)
        if it == nomes[0]:  #Se for o primeiro nome
            print(it, sep='', end='')       #imprime sem vírgula (aqui impedimos o print de adicionar espaços entre as impressões e de quebrar a linha no final)
        else:
            print(", ", it, sep='', end='') #Caso contrário, coloca uma vírgula e um espaço antes do nome
    print() #No final, quebra a filha
