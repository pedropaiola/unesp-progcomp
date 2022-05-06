/*
Problema: Eko
Categorias:
    binary search
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long int
    
using namespace std;
    
ll pos(vector<ll> &arvore, ll e, ll d, ll h)
{
    if (e > d)
        return d;
    ll med = (e + d)/2;
    if (arvore[med] > h)
        return pos(arvore, med+1, d, h);
    if (arvore[med] < h)
        return pos(arvore, e, med-1, h);
    return med;
}
    
int main()
{
    ll	n, m, i, e = 0, d = 0, med, h, soma, aux;
    vector<ll> arvore;
    vector<ll> somaH;
    
    scanf("%lld %lld", &n, &m);
    
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &aux);
        arvore.push_back(aux);
        d = max(aux, d);
    }
    
    sort(arvore.begin(), arvore.end(), greater<ll>());
    somaH.push_back(arvore[0]);
    for(i = 1; i < n; i++)
        somaH.push_back(arvore[i] + somaH[i-1]);
    
    while(d >= e)
    {
        med = (d + e)/2;
    
        i = pos(arvore, 0, n - 1, med);
        soma = somaH[i] - (i+1)*med;
        
        if (soma == m)
        {
            h = med;
            break;
        }
        if (soma < m)
            d = med - 1;
        else
        {
            h = med;
            e = med + 1;
        }
        
    }
    
    printf("%lld\n",h);
    
} 