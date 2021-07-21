/*
Problema: Marbles
Categorias:
	math > combinatorics
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll gcd(ll a, ll b){
    if (a % b == 0)
        return b;
    return gcd(b, a%b);
}

void divByGcd(ll &a, ll &b){
    ll g = gcd(a,b);
    a /= g;
    b /= g;
}

ll C(int n, int k){
    ll num = 1, den = 1;
    ll toMul, toDiv, i;
    if (k > n/2)
        k = n-k;
    for(i = k; i; i--){
        toMul=n-k+i;
        toDiv=i;
        divByGcd(toMul, toDiv);
        divByGcd(num, toDiv);
        divByGcd(toMul, den);
        num *= toMul;
        den *= toDiv;
    }
    return num/den;
}

int main(){
    int t, n, k;
    cin >> t;

    while(t--){
        cin >> n >> k;
        cout << C(n-1, k-1) << endl;
    }
}