/*
Problema: Game
Categorias:
	adhoc > sorting
Dificuldade: facil
Descricao: dado um vetor de inteiros, dois jogadores retiram um número por vez,
    alternando os turnos. O objetivo do primeiro jogador é minimizar o último
    número a ser retirado, e o objetivo do segundo é retirar. Qual o último número a sair?
Dica: Estratégia gulosa funciona neste caso. Se o jogador 1 quer miniminizar o
    último valor, então ele deve retirar o maior valor. Se o jogador 2 quer
    maximizar, então ele retira o menor.
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, aux;
    vector<int> a;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> aux;
        a.push_back(aux);
    }
    sort(a.begin(), a.end());

    //Não precisamos simular o processo para descobrir o número, tendo
    //os valores ordenados, sabemos que o último valor restante será a mediana.
    cout << a[(a.size() - 1)/2] << endl; 
}