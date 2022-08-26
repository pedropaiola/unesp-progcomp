/*
  Problema D - Dígitos Finais
  Calcular o que o enunciado pede, porém utilizando
  exponenciação por divisão e conquista e aritmética
  modular para chegar em uma solução eficiente.
*/
#include<bits/stdc++.h>
#define ll long long int

using namespace std;


/*
    Divisão e conquista: o cálculo da potência a^b pode ser
    descrita pela seguinte relação de recorrência:
    a^b = 1                     se b = 0
    a^b = a^(b/2) * a^(b/2)     se b é par
    a^b = a^(b/2) * a^(b/2) * a se b é ímpar
    Sendo que, obviamente, x^(b/2) não precisa ser calculado duas vezes
    Complexidade: O(log b)

    Aritmética modular: pelas propriedades da aritmética modular temos que
    (a^b) % m = ((a % m) ^ b) % m
    Ou seja, podemos aplicar o mod em todas as fases do cálculo da potência,
    impedindo que o número cresça além de m, economizando tempo e memória
*/

//Exponenciação modular com divisão e conquista
ll pot(ll a, ll b, int mod){
    if (b == 0)
        return 1;
    ll x = pot(a, b/2, mod);
    if (b % 2 == 0)
        return (x * x) % mod;
    return (((x * x) % mod) * (a % mod)) % mod;
}

//Exponenciação normal com divisão e conquista
ll pot(ll a, ll b){
    if (b == 0)
        return 1;
    int x = pot(a, b/2);
    if (b % 2 == 0)
        return x * x;
    return x * x * a;
}

int main(){
    int k;
    string a;
    ll b;
    cin >> a >> b >> k;
    if (k < a.size()){
        cout << pot(stoll(a.substr(a.size()-k, k)), b, pot(10, k)) << "\n";
    }else
        cout << pot(stoll(a), b, pot(10,k)) << "\n";
}