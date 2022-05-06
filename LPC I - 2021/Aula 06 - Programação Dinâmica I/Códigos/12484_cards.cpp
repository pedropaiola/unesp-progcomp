/*
Problema: Cards
Categorias:
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ALBERTO 0
#define WANDERLEY 1
#define ll long long int

using namespace std;

vector<long long int> dp[10000];

int n;
ll cartas[10000];

ll f(int jogador, int e, int d)
{
	if (e > d)
		return 0;
    if (dp[d][e] != -1)
        return dp[d][e];
	if (jogador == ALBERTO)
		dp[d][e] = max(f(WANDERLEY, e+1, d) + cartas[e], f(WANDERLEY, e, d-1) + cartas[d]);
	else
		dp[d][e] = min(f(ALBERTO, e+1, d), f(ALBERTO, e, d-1));
    return dp[d][e];
} 

int main()
{
	int i, j;
	for(i = 0; i < 10000; i++)
		dp[i].resize(i+1);
	while(cin >> n)
	{		
		for(i = 0; i < n; i++)
			for(j = 0; j <= i; j++)
				dp[i][j] = -1;
		for(i = 0; i < n; i++)
			cin >> cartas[i];
		cout << f(ALBERTO, 0, n-1) << endl;
	}	
}