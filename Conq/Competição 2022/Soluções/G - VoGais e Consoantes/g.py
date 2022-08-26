import sys

tot_vogais = 0
tot_consoantes = 0
for linha in sys.stdin:
    for c in linha:
        if c.isalpha():
            if c.lower() in ['a', 'e', 'i', 'o', 'u']:
                tot_vogais += 1
            else:
                tot_consoantes += 1

if tot_vogais > 0:
    if tot_vogais == 1:
        print(tot_vogais, "vogal")
    else:
        print(tot_vogais, "vogais")
if tot_consoantes > 0:
    if tot_consoantes == 1:
        print(tot_consoantes, "consoante")
    else:
        print(tot_consoantes, "consoantes")
