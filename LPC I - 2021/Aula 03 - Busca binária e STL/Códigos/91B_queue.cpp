/*
Problema: Queue
Categorias:
    binary search
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
    
using namespace std;
    
int main(){
    int n, i, x;
    vector<int> idade, vetAux;
    
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        idade.push_back(x);
        vetAux.push_back(0);
    }
    
    vetAux[n - 1] = idade[n - 1];
    for(i = n - 2; i >= 0; i--){
        vetAux[i] = min(idade[i], vetAux[i+1]);
    }
    
    int resp = lower_bound(vetAux.begin(), vetAux.end(), idade[0]) - vetAux.begin() - 2;
    resp = max(resp, -1);
    cout << resp;
    for(i = 1; i < n; i++){
        resp = lower_bound(vetAux.begin() + 1, vetAux.end(), idade[i]) - vetAux.begin() - i - 2;
        resp = max(resp, -1);
        cout << " " << resp;
    }
    cout << endl;
}