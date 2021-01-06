/*
Problema: Coins Game
Categorias:
	dynamic programming
	math > game theory
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX 1000001

using namespace std;

bool dp[MAX];
int K, L;

void preProcess()
{
	dp[0] = false;
	for(int i = 1; i < MAX; i++)
	{
		dp[i] = true;	
		if (!dp[i-1])
			continue;
		if (i - L >= 0 && !dp[i-L])
			continue;
		if (i - K >= 0 && !dp[i-K])
			continue;
		dp[i] = false;
	}
}

int main()
{
	int m, n;
	cin >> K >> L >> m;
	preProcess();
	for(int i = 0; i < m; i++)
	{
		cin >> n;
		cout << (dp[n] ? "A" : "B");
	}
	cout << endl;
}