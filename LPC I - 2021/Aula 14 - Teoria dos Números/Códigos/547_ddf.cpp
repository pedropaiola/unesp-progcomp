/*
Problema: DDF
Categorias:
	math > number theory
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 3001

using namespace std;

int prox[MAXN];
int tam[MAXN];

int somaDigitos(int x){
    int soma = 0;
    while(x != 0){
        soma += x % 10;
        x /= 10;
    }
    return soma;
}

void preprocessDDF(){
    int somaDig;
    for(int x = 1; x < MAXN; x++){
        somaDig = somaDigitos(x);
        for(int y = x; y < MAXN; y += x){
            prox[y] += somaDig;
        }
    }
}

int dfs(int x){
    if (tam[x] != 0)
        return tam[x];
    tam[x] = 1;
    if (x != prox[x])
        tam[x] += dfs(prox[x]);
    return tam[x];
}

void exibirSeq(int x){
    cout << x;
    while(x != prox[x]){
        x = prox[x];
        cout << " " << x;
    }
    cout << endl;
}

int main()
{
    int n, m, k;
    int melhorNum, melhorTam;
    preprocessDDF();
    tam[0] = tam[1] = 1;
    k = 1;
    while(cin >> n >> m){
    	cout << "Input" << k << ": " << n << " " << m << endl;
    	if (n > m) swap(m, n);
        melhorNum = melhorTam = 0;
        for(;n <= m; n++){
            if (dfs(n) > melhorTam){
                melhorTam = dfs(n);
                melhorNum = n;
            }
        }
        cout << "Output" << k << ": ";
        exibirSeq(melhorNum);
        k++;
    }
}