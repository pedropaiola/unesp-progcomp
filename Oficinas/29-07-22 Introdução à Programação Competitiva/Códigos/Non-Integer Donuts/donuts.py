import os

n = int(input())
str = input()
centavos = int(str[str.find(".") + 1 : len(str)])
atrasado = 0

for i in range(n):
    str = input()
    decimal = int(str[str.find(".") + 1 : len(str)])
    centavos = (centavos + decimal) % 100
    
    if centavos != 0:
        atrasado = atrasado + 1
        
print(atrasado)