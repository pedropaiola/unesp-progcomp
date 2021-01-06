/*
Problema: Win or Freeze
Categorias:
	math > game theory
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> fatoresPrimos(ll q)
{
	vector<ll> fatores;
    ll p = 2;
    while(q > 1 && p * p <= q){
        if (q % p == 0)
        {
            fatores.push_back(p);
            q /= p;
        }
        else
            p++;
    }
    if (q > 1)
        fatores.push_back(q);
    return fatores;
}

int main()
{
	ll q;
	cin >> q;
    vector<ll> fatores = fatoresPrimos(q);
    if (fatores.size() <= 1)
        cout << 1 << endl << 0 << endl;
    else if (fatores.size() == 2)
        cout << 2 << endl;
    else
        cout << 1 << endl << fatores[0]*fatores[1] << endl;
}