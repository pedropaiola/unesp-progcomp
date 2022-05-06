/*
Problema: Longest Perfect Increasing Subsequence
Categorias:
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i;
    cin >> n;

    int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    
    map<int, int> dp;

    int resp = 0;
    for(i = 0; i < n; i++){
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (dp[a[i]] > resp){
            resp = dp[a[i]];
        }
    }

    cout << resp << endl;
}