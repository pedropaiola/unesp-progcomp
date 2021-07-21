/*
Problema: Mountain Ranges
Categorias:
	math > ad-hoc
Dificuldade: muito facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    int dif[1000];
    int alt, altAnt;
    cin >> n >> x;
    cin >> altAnt;
    for(int i = 0; i < n - 1; i++){
        cin >> alt;
        dif[i] = abs(alt - altAnt);
        altAnt = alt;
    }
    int maiorSeg = 0;
    int segAtual = 0;
    for(int i = 0; i < n - 1; i++){
        if (dif[i] <= x){
            segAtual++;
            maiorSeg = max(maiorSeg, segAtual);
        } else {
            segAtual = 0;
        }
    }
    maiorSeg++;
    cout << maiorSeg << endl;
}