/*
Problema: Aggressive cows
Categorias:
	binary search
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long
    
using namespace std;
    
int main()
{
    ll t, n, c, i;
    vector<ll> pos;
    
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &c);
        pos.resize(n);
        
        for(i = 0; i < n; i++)
            scanf("%lld", &pos[i]);
        
        sort(pos.begin(), pos.end());
        
        ll e = 0, d = pos[n-1], m;
        ll ultimaVaca, vacasColocadas;
        ll maiorDist = 0, dist;
        
        while(d >= e)
        {
            m = (e + d)/2;
            
            ultimaVaca = 0;
            vacasColocadas = 1;
            dist = pos[n-1] + 1;
            
            for(i = 1; i < n; i++)
            {
                if (pos[i] - pos[ultimaVaca] >= m)
                {
                    dist = min(dist, pos[i] - pos[ultimaVaca]);
                    ultimaVaca = i;
                    vacasColocadas++;
                }
            }
            if (vacasColocadas >= c)
            {
                maiorDist = max(maiorDist, dist);
                e = dist + 1;
            }
            else
                d = m - 1;
        }
        printf("%lld\n",maiorDist);
    }
} 