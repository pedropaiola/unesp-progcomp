'''
Problema: Bishops
Categorias:
	math
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
'''
while True:
    try:
        n = int(input())
        print(max(1, 2*n - 2))
    except EOFError:
        break