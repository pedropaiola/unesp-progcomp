//Programa auxiliar para gerar os vetores prox e tam que serão inseridos
//no programa principal (que será submetido)
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

int main()
{
    preprocessDDF();
    
    cout << "int prox[] = {";
    for(int i = 0; i < MAXN - 1; i++){
        cout << prox[i] << ", ";
    }
    cout << prox[MAXN-1] << "};" << endl;

    cout << "int tam[] = {";
    for(int i = 0; i < MAXN - 1; i++){
        cout << dfs(i) << ", ";
    }
    cout << dfs(MAXN-1) << "};" << endl;
}