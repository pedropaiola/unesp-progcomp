/*
Problema: Riding in a Lift
Categorias:
	math > modular arithmetic
    dynamic programming
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define mod 1000000007 

using namespace std;

int dp[5001][5001];
int sum[5001][2];
int b, n;

int add(int a, int b){  
    a += b;
    if (a >= mod)
        a -= mod;
    if (a < 0)
        a += mod;
    return a;   
}

int sub(int a, int b){
    return (a - b + mod) % mod;
}

int solve(int a, int k){
    int j, i, limit;
    int flag = 0;
    //1o: calculando para k = 1
    sum[0][0] = sum[0][1] = 0;
    for(i = 1; i <= n; i++){
        limit = abs(b - i) - 1;
        dp[i][1] = min(limit, i - 1) + min(limit, n - i);
        sum[i][flag] = add(dp[i][1], sum[i-1][flag]);
    }
    //2º: calculando até k
    for(j = 2; j <= k; j++){
        flag = (flag + 1) % 2;
        for(i = 1; i <= n; i++){
            limit = abs(b-i) - 1;
            int ini = max(1, i - limit) - 1;
            int fim = min(n, i + limit);
            dp[i][j] = sub(sum[fim][!flag], sum[ini][!flag]);
            dp[i][j] = sub(dp[i][j], dp[i][j-1]);
            sum[i][flag] = add(dp[i][j], sum[i-1][flag]);
        }
    }
    return dp[a][k];
}

int main(){
    int a, k;
    cin >> n >> a >> b >> k;
    cout << solve(a,k) << endl;
}