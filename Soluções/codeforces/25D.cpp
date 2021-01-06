/*
Problema: Roads not only in Berland
Categorias:
	data structure > disjoint set
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 1000

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

bool same(int a, int b){
    return find(a) == find(b);
}

int main(){
    int n, a, b, i;
    vector<pair<int, int> > sai, entra;
    cin >> n;
    init(n);
    //Lendo as estradas atuais e já verificando quais são redundantes (que serão fechadas)
    for(i = 0; i < n - 1; i++){
        cin >> a >> b;
        if (same(a-1,b-1)){
            sai.push_back({a,b});
        } else {
            merge(a-1,b-1);
        }
    }
    //Para cada estrada que saiu, temos que colocar uma nova. Considerando que o grafo é bidirecionado,
    //Vamos partir da cidade 1 e conectar a todas as outras que ainda não estão no seu conjunto. No final,
    //o grafo será conexo
    for(i = 1; i < n; i++){
        if (same(0, i))
            continue;
        merge(0, i);
        entra.push_back({1, i+1});
    }
    cout << sai.size() << endl;
    for(i = 0; i < sai.size(); i++){
        cout << sai[i].first << " " << sai[i].second << " " << entra[i].first << " " << entra[i].second << endl;
    }
}