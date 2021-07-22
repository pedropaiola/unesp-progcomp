/*
Problema: B - Bolinhas de Gude / Marbles
Categorias:
	math > game theory
    dynamic programming
    data structure > bitset
    maratona > regional 2018
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_NIMBER 310

#define MAX_N 101

using namespace std;

int dp[MAX_N][MAX_N];

int init(){
    memset(dp, -1, sizeof(dp));
    dp[1][2] = dp[2][1] = 0;

}

int g(int l, int c){
    if (dp[l][c] != -1)
        return dp[l][c];
    bitset<MAX_NIMBER> mexs;
    int u;

    if (l != c)
        for(u = 1; u < min(l, c); u++)
            mexs.set(g(l-u, c-u));
    for(u = 1; u < l; u++)
        if (l-u != c)
            mexs.set(g(l-u, c));
    for(u = 1; u < c; u++)
        if (c-u != l)
            mexs.set(g(l, c-u));
    
    for(int x = 0; x < MAX_NIMBER; x++)
        if (!mexs.test(x))
            return dp[l][c] = x;
}

int main(){
    int n, l, c, resp = 0;
    cin >> n;
    init();
    for(int i = 0; i < n; i++){
        cin >> l >> c;
        resp ^= g(l, c);
    }
    cout << (resp ? "Y" : "N") << endl;
}

