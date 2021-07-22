/*
Problema: 3-Palindromes
Categorias:
    strings > palindromes
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 1000005
#define ll long long int

using namespace std;

ll d1[MAXN], d2[MAXN];
ll sum[MAXN], cnt[MAXN][3];
string s;
ll n;

void manacher(){
    for (ll i = 0, l = 0, r = -1; i < n; i++) {
        ll k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (ll i = 0, l = 0, r = -1; i < n; i++) {
        ll k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
}

inline ll dig(ll i){
    return (ll)(s[i] - '0');
}

void preProcess(){
    /*
    Pré-computador 3 vetores de soma de prefixos:
    cnt[i][j] = # de números n = s[0]...s[k], k <= i | n % 3 = j
    consulta: cnt[b][j] - cnt[a-1][j] -> # de números n = s[a]...s[k], k <= b | n % 3 = j
    */
    memset(cnt, 0, sizeof(cnt));
    ll total = 0;
    for(ll i = 0; i < n; i++){
        total += dig(i);
        total %= 3;
        sum[i] = total;
        if(i != 0){
            for(ll j = 0; j < 3; j++)
                cnt[i][j] += cnt[i-1][j];
        }
        if (dig(i) != 0)
            cnt[i][total] += 1;
    }
}

ll contPalin3(){
    /*
    Ideia geral: dado um palíndromo ímpar com centro em i de tamanho k*2 + 1 temos que:
    n = s[i-k]...s[i-1]s[i]s[i+1]...s[i+k]
    Como isto é um palíndromo, sabemos que a soma dos dígitos % 3 de s[i-k]...s[i-1] é igual a s[i+1]...s[i+k]
        x = somaDig(s[i-k]...s[i-1]) = somaDig(s[i+1]...s[i+k])
    Como estamos procurando números divisíveis por 3, estamos procurando palíndromos que satisfaçam:
        (s[i] + 2*x) % 3 = 0
    Conhecendo a # de palíndromos com centro em i e pré-computando os restos de cada substring, podemos
    calcular em tempo linear quantos palíndromos satisfazem essa propriedade.
    */
    ll cont = 0;
    
    for(ll i = 0; i < n; i++){
        ll k = d1[i];
        k--;
        ll digit = dig(i) % 3;
        if (digit == 0)
            cont++;

        if (k == 0)
            continue;
        ll req = digit;
        req = (req + sum[i] + 3)%3;
        cont += cnt[i+k][req] - cnt[i][req];
    }

    for(ll i = 0; i < n; i++){
        ll k = d2[i];
        if (k == 0)
            continue;
        ll digit = (dig(i-1) + dig(i))%3;
        if (digit == 0 && !(dig(i) == 0 && dig(i-1)==0))
            cont++;
        ll req = digit;
        req = (req + sum[i] + 3) % 3;
        cont += cnt[i+k-1][req] - cnt[i][req];
    }
    
    return cont;
}

int main(){
    cin >> s;
    n = (ll)s.size();

    manacher();
    preProcess();

    cout << contPalin3() << endl; 
}