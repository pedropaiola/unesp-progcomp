/*
Problema: Squares
Categorias:
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
using namespace std;

map<int, int> memo;

int troco(int x){
    if (x == 0)
        return 0;
    if (memo.count(x))
        return memo[x];
    
    memo[x] = INT_MAX;
    for(int m = 1; m*m <= x; m++){
        memo[x] = min(memo[x], 1 + troco(x-m*m));
    }
    return memo[x];
}

int main()
{
	int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << troco(n) << endl;
    }
}