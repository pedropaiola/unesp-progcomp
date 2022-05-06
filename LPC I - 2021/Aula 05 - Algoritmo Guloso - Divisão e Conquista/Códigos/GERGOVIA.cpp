/*
Problema: Wine trading in Gergovia
Categorias:
    greedy
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAXN 100001
#define ll long long int 

using namespace std;

int main()
{
	ll n, resp;
	ll val[MAXN];
	while (true)
	{
        cin >> n;
		if (n == 0)
			break;

		resp = 0;
        cin >> val[0];
        resp += abs(val[0]);
		for (int i = 1; i < n; i++)
		{
			cin >> val[i];
            val[i] += val[i - 1];
            resp += abs(val[i]);
		}
		cout << resp << endl;
	}
}