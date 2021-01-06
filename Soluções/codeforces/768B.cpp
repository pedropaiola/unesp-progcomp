/*
Problema: Code for 1
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

ll valor(ll i, ll n, ll l, ll r){
    //cout << i << " " << n << " (" << l << " " << r << ")" << endl;
    if (n <= 1)
        return n;
    if (r - l == 0){
        return n/2;
    }

    ll interv = r - l;
    ll meio = l + interv/2;
    if (meio == i)
        return n % 2;
    
    ll l1 = l, r1 = meio - 1, l2 = meio + 1, r2 = r;
    if (i >= l1 && i <= r1)
        return valor(i, n/2, l1, r1);
    else
        return valor(i, n/2, l2, r2);    
}

int main(){
    ll n, l, r, i, lim, cont = 0;
    cin >> n >> l >> r;
    l--; r--;
    lim = pow(2, (int)(log(n)/log(2))+1) - 1;
    for(i = l; i <= r; i++){
        cont += valor(i, n, 0, lim);
    }
    cout << cont << endl;
}