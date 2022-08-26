/*
  Problema A - Aperto de Mão
  Este problema pode ser modelado através de uma equação de segundo grau
  (se houver dúvidas sobre isso, assistir o vídeo da resolução). O código
  basicamente calcula a raiz desta equação (desconsiderando a negativa)
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
   int N, cumprimentos;
   cin >> N;

   for (int i=1; i<=N; i++) 
   {
     double delta, x1, x2;
     cin >> cumprimentos;

     delta = 1 -(4*1*(-2*cumprimentos));
     x1 = (1 + sqrt(delta)) / 2;
     // x2 = (1 - sqrt(delta)) / 2;

     cout << x1 << endl;     
   }
}