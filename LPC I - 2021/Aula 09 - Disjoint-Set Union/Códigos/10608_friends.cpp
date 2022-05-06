/*
Problema: Friends
Categorias:
    data structure > disjoint set
Dificuldade: muito facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 30000

using namespace std;

int p[MAXN];
int tam[MAXN];

void init(int n){
    for(int i = 0; i < n; i++){
        p[i] = i;
        tam[i] = 1; //A principio, cada conjunto contém apenas ele mesmo
    }
}

int find(int x){
    if (p[x] == x) 
        return x;
    return p[x] = find(p[x]); //Aplicando path compression
}

void merge(int a, int b){
    int setA = find(a);
    int setB = find(b);
    if (setA == setB) //Ja sao o mesmo conjunto
        return;
    if (tam[setA] > tam[setB])
        swap(setA, setB);   //queremos que setU seja o menor conjunto
    p[setA] = setB;         //liga a em b
    tam[setB] += tam[setA]; //atualiza o tamanho de b
}

int main(){
    int t, n, m, a, b, i;
    int maxf;
    cin >> t;
    while(t--){
        cin >> n >> m;
        init(n);
        maxf = 0;
        for(i = 0; i < m; i++){
            cin >> a >> b;
            merge(a-1, b-1);
        }
        for(i = 0; i < n; i++){
            maxf = max(maxf, tam[i]);
        }
        cout << maxf << endl;
    }
}