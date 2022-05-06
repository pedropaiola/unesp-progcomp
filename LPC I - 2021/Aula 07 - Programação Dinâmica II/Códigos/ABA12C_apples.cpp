/*
Problema: Buns
Categorias:
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola/Giulia
*/
#include<bits/stdc++.h>
#define MAXK 101
#define ll long long int

using namespace std;

int main(){
    int t, n, k, i, j, aux;

    cin >> t;
    while(t--){
        vector<int> preco, qtde;

        cin >> n >> k;
        for(i = 0; i < k; i++){
            cin >> aux;
            if (aux != -1)
            {
                qtde.push_back(i+1);
                preco.push_back(aux);
            }
        }

        int dp[MAXK];
        dp[0] = 0;
        for(j = 1; j <= k; j++){
            dp[j] = INT_MAX;
            for(i = 0; i < qtde.size(); i++){
                if (qtde[i] > j)
                    break;
                if (dp[j-qtde[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j-qtde[i]] + preco[i]);
            }
        }

        if (dp[k] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dp[k] << endl;
    }
}