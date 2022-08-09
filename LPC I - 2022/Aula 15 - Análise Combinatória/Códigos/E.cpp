/*
E - Problem Makes Problem
https://lightoj.com/problem/problem-makes-problem

Resolução a partir do Método Bola Traço da Análise Combinatória
*/

#include <bits/stdc++.h>

#define MAX 2000000
#define MOD 1000000007

using namespace std;

vector<long long> fact(MAX + 1);

long long pow_mod(long long b, long long x){
    long long val = 1LL;

    while(x){
        if(x & 1){
            val = (val * b) % MOD;
        }

        b = (b * b) % MOD;
        x >>= 1;
    }

    return val;
}

long long comb(long long n, long long k) {
    // calcular combinação nCk => (n!) / (k! * (n - k)!)
    // n = n + k - 1
    // k = k - 1
    long long q, d;
    q = fact[n]; // q = (n!)
    d = (fact[k] * fact[n - k]) % MOD; // d = (k! * (n - k)!)

    // cálculo do módulo inverso para retornar valor correto da divisão com módulo
    // assim, (q / d) % MOD => (q * modInverso(d)) % MOD
    // modInverso(d) => potência de d elevado ao MOD - 2
    return (q * pow_mod(d, MOD - 2)) % MOD;
}

void factorial() {
    fact[0] = 1LL;

    for (int i = 1; i <= MAX; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        long long n, k;
        cin >> n >> k;
        cout << "Case " << t << ": " << comb(n + k - 1, k - 1) << "\n";
    }

    return 0;
}