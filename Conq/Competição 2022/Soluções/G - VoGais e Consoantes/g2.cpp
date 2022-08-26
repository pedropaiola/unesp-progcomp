/*
  Problema G - Vogais e Consoantes
  Ler cada linha e pesquisar caracter por caracter verificando
  se é vogal ou consoante (maiúscula ou minúscula). Cuidado para
  impressão final observando o singlar e plural para vogal ou vogais e
  consoante ou consoantes.
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tot_vogais, tot_consoantes;
    string linha;

    tot_vogais = 0;
    tot_consoantes = 0;
    while (getline(cin, linha)) {
        for (int i = 0; i < linha.size(); i++) 
        {
            char c = tolower(linha[i]);
            if (isalpha(c)){
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    tot_vogais++;
                else
                    tot_consoantes++;
            }
        }
    }
    if (tot_vogais > 0) {
        cout << tot_vogais << (tot_vogais == 1 ? " vogal" : " vogais") << endl;
    }
    if (tot_consoantes > 0) {
        cout << tot_consoantes << (tot_consoantes == 1 ? " consoante" : " consoantes") << endl;
    }
    return 0;
}