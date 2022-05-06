/*
Problema: Heide Learns Hashing (Easy)
Categorias:
    ad-hoc > brute force
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

pair<ll, ll> solve(ll r){
    ll x, y;
    for(x = 1; x*x < r; x++){
        y = r - x*x - x - 1;
        if (y <= 0)
            break;
        if ((y % (2*x)) == 0)
            return {x, y / (2*x)};
    }
    return {-1, -1};
}

int main(){
    ll r;
    pair<ll, ll> resp;

    cin >> r;
    resp = solve(r);

    if (resp.first == -1)
        cout << "NO" << endl;
    else
        cout << resp.first << " " << resp.second << endl;
}