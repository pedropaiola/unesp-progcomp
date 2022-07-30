from collections import deque #módulo Python com a implementação de um deque (double queue)
                              #que também pode ser usado como uma pilha ou uma fila

n = int(input())
for k in range(n):
    s = input()
    pilha = deque() #deque para auxiliar na tarefa deste problema (utilizando como pilha)
    resp = 0
    #Percorrendo todos os caracteres de nossa string
    for i in range(0, len(s)):
        if s[i] == '<':         #Se o caractere for um <
            pilha.append(s[i])  #empilhamos ele
        elif s[i] == '>' and len(pilha) > 0:
            #Se o caractere for > e a pilha não estiver vazia,
            #é pq temos um "diamante", como <....>
            pilha.pop()     #tiramos o < da pilha
            resp = resp + 1 #e incrementamos a resposta
    print(resp)