t = int(input())

for k in range(t):  #para cada caso de teste k = 0, 1, ..., t-1
    precos = {} #instaciando o map (chamado de dict, no Python)
    total = 0

    n = int(input())
    #Lendo cada um dos itens e seus valores unitários
    for i in range(n):
        item, valor = input().split()
        precos[item] = float(valor) #Armazenando no dict
    
    m = int(input())
    #Lendo a lista de compras
    for i in range(m):
        item, qtde = input().split()
        total = total + precos[item] * int(qtde)
        
    print("R$ {:.2f}".format(total))