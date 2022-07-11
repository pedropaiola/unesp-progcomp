/*
Problema: Maximum Median
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

vector<ll> vet;

inline bool ehPossivel(ll x, ll k){
    ll qtdeOp = 0;
    for(int i = vet.size()/2; i < vet.size() && vet[i] < x; i++){
        qtdeOp += x - vet[i];
    }
    return qtdeOp <= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll k, aux;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> aux;
        vet.push_back(aux);
    }
    sort(vet.begin(), vet.end());

    ll e = vet[n/2], d = vet[n-1]+k, med;
    ll maiorMed;
    while(e <= d){
        med = (e + d)/2;
        if (ehPossivel(med, k))
        {
            e = med + 1;
            maiorMed = med;
        }
        else
            d = med - 1;
    }
    cout << maiorMed << "\n";
}