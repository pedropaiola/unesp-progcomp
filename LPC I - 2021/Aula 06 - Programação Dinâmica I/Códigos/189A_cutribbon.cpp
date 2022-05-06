/*
Problema: Cut Ribbon
Categorias:
    dynamic programming
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 4001

using namespace std;

int dp[MAXN];
int cortes[3];

int max_cut(int n){
    if (dp[n] != -1)
        return dp[n];
    dp[n] = -5000000;
    for(int i = 0; i < 3; i++){
        if (cortes[i] <= n)
            dp[n] = max(dp[n], 1 + max_cut(n-cortes[i]));
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n >> cortes[0] >> cortes[1] >> cortes[2];

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    cout << max_cut(n) << endl;
}