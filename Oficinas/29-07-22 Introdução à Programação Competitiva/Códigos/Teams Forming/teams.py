n = int(input())
a = [int(x) for x in input().split()]   #Criando lista de inteiros a partir da entrada

#Ordenando a lista
a = sorted(a)

resp = 0
#Percorrendo as posições i = 1, 3, 5, ... 
for i in range(1, n, 2):
    resp = resp + a[i] - a[i-1]

print(resp)