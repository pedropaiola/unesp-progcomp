import heapq    #módulo Python com a implementação de uma heap

while True: #Loop "eterno"
    n = int(input())
    if n == 0:  #Se n == 0
        break   #encerra-se o loop

    #Lendo os valores a serem somados, e armazenado em uma lista
    pq = [int(x) for x in input().split()] 
    #Transformando a lista em uma fila de prioridades (heap-mínima)
    heapq.heapify(pq)

    resp = 0
    while len(pq) > 1:  #Enquanto a fila tiver pelo menos dois elementos (ainda não somamos tudo)
        #Obtemos os dos primeiros elementos do topo
        a = heapq.heappop(pq) #Obtém o topo da fila de prioridades e já o retira desta estrutura
        b = heapq.heappop(pq)
        #Somamos e adicionamos o custo na resposta
        resp += a+b
        #Adicionamos a soma na fila de prioridades (para ser utilizada em alguma soma futura)
        heapq.heappush(pq, a+b)
    #Imprime total dos custos
    print(resp)