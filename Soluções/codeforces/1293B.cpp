/*
Problema: JOE is on TV!
Categorias:
	math > combinatorics
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    double d = 0;
    cin >> n;
    for(int i = n; i >= 1; i--){
        d += 1.0/i;
    }
    cout << d << endl;
}