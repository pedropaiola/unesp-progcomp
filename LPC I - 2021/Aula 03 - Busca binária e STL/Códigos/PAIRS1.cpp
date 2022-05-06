/*
Problema: Count the Pairs
Categorias:
    data structure > map
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k, x, i, numPares = 0;
    map<long long int, int> hash;
    vector<long long int> numeros;

    cin >> n >> k;

    for(i = 0; i < n; i++){
        cin >> x;
        numeros.push_back(x);
        hash[x] = 1;
    }

    for(auto v : numeros){
        if (hash.count(v + k)){
            numPares += 1;
        }
    }

    cout << numPares << endl;
}