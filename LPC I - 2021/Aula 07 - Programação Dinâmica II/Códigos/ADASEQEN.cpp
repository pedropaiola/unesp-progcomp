/*
Problema: Ada and Subsequence
Categorias:
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int lcs(string x, string y, int price[]){
    int m = x.size();
    int n = y.size();
    int dp[m+1][n+1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1] + price[x[i-1] - 'a'];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main(){
    int m, n;
    string x, y;
    int price[26];

    cin >> m >> n;
    for(int i = 0; i < 26; i++){
        cin >> price[i];
    }
    cin >> x;
    cin >> y;
    cout << lcs(x, y, price) << endl;
}