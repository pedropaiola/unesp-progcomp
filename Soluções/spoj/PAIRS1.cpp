/*
Problema: Count the Pairs
Categorias:
	data structure > map
    data structure > set
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
    set<long long int> numeros;

    cin >> n >> k;

    for(i = 0; i < n; i++){
        cin >> x;
        numeros.insert(x);
        if (hash.count(x))
            hash[x]++;
        else
            hash[x] = 1;
    }

    for(set<long long int>::iterator it = numeros.begin(); it != numeros.end(); it++){
        if (hash.count(*it + k)){
            numPares += max(hash[*it], hash[*it + k]);
        }
    }

    cout << numPares << endl;
}