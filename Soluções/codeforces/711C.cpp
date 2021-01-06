/*
Problema: Coloring Trees
Categorias:
	dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 101
#define ll long long int
#define INF 1e+15

using namespace std;

int n, m, k;
int estadoInicial[MAXN];
ll custo[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXN]; //dp[pos][cor][beauty]

void init(){
    int i, j, l;
    for(i = 0; i <= n; i++)
        for(j = 0; j <= m; j++)
            for(l = 0; l <= k; l++)
                dp[i][j][l] = -1;
}

ll solve(int i, int j, int p){
    //Se já temos mais partições que as desejadas
    if (p > k){
        return INF;
    }
    //Se já foi calculado
    if (dp[i][j][p] != -1)
        return dp[i][j][p];
    //Se é a ultima posição (temos que verificar se é uma solução válida, ou seja, p == k)
    if (i == n){
        if (p == k) return dp[i][j][p] = 0;
        return dp[i][j][p] = INF;
    }
    
    //Se a próxima posição já está pintada
    if (estadoInicial[i+1])
    {
        dp[i][j][p] = solve(i+1, estadoInicial[i+1], p + (j != estadoInicial[i+1]));
    }  
    else //Caso contrário
    {
        //Selecionamos as possíveis cores para a próxima posição
        dp[i][j][p] = INF;
        for(int c = 1; c <= m; c++){
            dp[i][j][p] = min(dp[i][j][p], custo[i+1][c] + solve(i+1, c, p + (j != c)));
        }
    }
    return dp[i][j][p];
}


int main(){
    int i, j;
    cin >> n >> m >> k;
    init();
    for(i = 1; i <= n; i++){
        cin >> estadoInicial[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            cin >> custo[i][j];
        }
    }
    ll resp = solve(0,0,0);
    if (resp >= INF)
        cout << "-1" << endl;
    else
        cout << resp << endl;    
}