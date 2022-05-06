/*
Problema: Encode Integer
Categorias:
    greedy
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int encode(int n){
    if (n == 0)
        return 10;
        
    vector<int> digs;
    for(int div = 9; div >= 2; div--){
        while(n % div == 0)
        {
            n /= div;
            digs.push_back(div);
        }
    }
    if (n > 1)
        return -1;
    
    int resp = 0;
    int pot = 1;
    for(int i = 0; i < digs.size(); i++){
        resp += digs[i] * pot;
        pot *= 10;
    }
    return resp;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << encode(n) << endl;
    }
}