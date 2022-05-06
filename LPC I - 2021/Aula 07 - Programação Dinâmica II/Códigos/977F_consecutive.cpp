/*
Problema: Consecutive Subsequence
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

    int resp = 0, ant = 0;
    for(i = 0; i < n; i++){
        dp[a[i]] = dp[a[i] - 1] + 1;
        if (dp[a[i]] > resp){
            resp = dp[a[i]];
            ant = a[i];
        }
    }

    vector<int> seq;
    for(i = n-1; i >= 0; i--){
        if (a[i] == ant){
            seq.push_back(i+1);
            ant--;
        }
    }

    cout << resp << endl;
    for(i = seq.size() - 1; i > 0; i--)
        cout << seq[i] << " ";
    cout << seq[0] << endl;
}