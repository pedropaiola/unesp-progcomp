/*
Problema: T-primes
Categorias:
	math
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long int
#define MAXN (int)1e6

using namespace std;

bool ehPrimo[MAXN+1];

void crivo(){
    memset(ehPrimo, true, sizeof(ehPrimo));
    ehPrimo[0] = ehPrimo[1] = false;
    for(int p = 2; p * p <= MAXN; p++){
        if (ehPrimo[p]){
            for(int i = p*p; i <= MAXN; i += p)
                ehPrimo[i] = false;
        }
    }
}

int main(){
    int n;
    ll x, r;
    cin >> n;
    crivo();
    while(n--){
        cin >> x;
        r = sqrt(x);
        cout << (r*r == x && ehPrimo[r] ? "YES" : "NO") << endl;
    }
}