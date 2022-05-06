/*
Problema: Buns
Categorias:
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola/Giulia
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int B[11];
int C[11];
int D[11];
int A[11];
int m;

int memo[1001][11];

int pd(int n, int recheio)
{
	if (n <= 0 || recheio == -1)	
		return 0;
	if (memo[n][recheio] != -1)
		return memo[n][recheio];
	int maxx = 0;
	
	if (recheio == 0)
	{
		maxx = (n/C[0])*D[0];
	}
	else
	{
		int i = 0;
		while(i*B[recheio] <= A[recheio] && i*C[recheio] <= n)
		{
			maxx = max(maxx, i*D[recheio] + pd(n - i*C[recheio], recheio - 1));
			i++;
		}
	}
	memo[n][recheio] = maxx;
	return maxx;
}

int main()
{
	int n;
	
	cin >> n >> m >> C[0] >> D[0];
	B[0] = 0;
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
			memo[i][j] = -1;
	for(int i = 1; i <= m; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	cout << pd(n, m) << endl;
}