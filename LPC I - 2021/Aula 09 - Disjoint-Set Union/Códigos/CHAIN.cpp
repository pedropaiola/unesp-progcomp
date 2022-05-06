/*
Problema: Strange Food Chain
Categorias:
	data structure > disjoint set
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<iostream>
#define MAX_N 150000
#define MAX_REAL 50000

using namespace std;

int pai[MAX_N+1];
int tam[MAX_N+1];

void init() {
	for (int i = 1; i <= MAX_REAL; ++i) {
		pai[i] = i;
		tam[i] = 1;
	}
	for (int i = MAX_REAL + 1; i <= MAX_N; ++i) {
		pai[i] = -1;
		tam[i] = 0;
	}
}

int find(int x) {
	if (pai[x] == x || pai[x] == -1) 
		return x;
	else             
		return pai[x] = find(pai[x]);
}

bool same(int x, int y)
{
	return (find(x) == find(y));
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (tam[a] < tam[b]) 
		swap(a, b);
	 
	pai[b] = a;
	tam[a] += tam[b];
}	

int presa(int x)
{
	return MAX_REAL + x;	
}

int predador(int x)
{
	return 2*MAX_REAL + x;
}

int main()
{
	int t, n, k, d, x, y, falsos;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> k;
		init();
		falsos = 0;
		for(int j = 0; j < k; j++)
		{
			cin >> d >> x >> y;
			
			if (x > n || y > n)
			{
				//cout << " F\n";
				falsos++;
				continue;
			}
			
			if (d == 1)
			{
				if (same(x,presa(y)) || same(x,predador(y))) 
				{
					//cout << " F\n";
					falsos++;
					continue;
				}
				merge(x,y);
				merge(predador(x), predador(y));
				merge(presa(x), presa(y));
			}
			else if (d == 2)
			{
				if (x == y || same(x,y) || same(x,presa(y))) 
				{
					//cout << " F\n";
					falsos++;
					continue;
				}
				merge(presa(x), y);
				merge(x, predador(y));
				merge(presa(y), predador(x));
			}
		}
		cout << falsos << endl;
	}
}