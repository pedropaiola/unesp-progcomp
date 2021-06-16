/*
Problema: Ada and Branches
Categorias:
	data structure > disjoint set
Dificuldade: dificil
Descricao:
Dica: 
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 100000

using namespace std;

int p[MAXN];
int tam[MAXN];

typedef struct{
    int w;
    int a;
    int b;
    int i;
} op;

bool comp(op x, op y){
    if (x.w == y.w)
        return x.i < y.i; //i=-1 representa um merge, que deve acontecer antes do find (se possuem o mesmo peso)
    return x.w > y.w;
}

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

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
    int i, a, b, w;
    vector<op> ent;
    int queries[3*MAXN];

    cin >> n >> m >> q;
    init(n);
    for(i = 0; i < m; i++){
        cin >> a >> b >> w;
        ent.push_back({w, a, b, -1});
    }

    for(i = 0; i < q; i++){
        cin >> a >> w;
        ent.push_back({w, a, -1, i});
    }

    sort(ent.begin(), ent.end(), comp);
    for(auto e : ent){
        if (e.i == -1){
            merge(e.a, e.b);
        } else {
            queries[e.i] = tam[find(e.a)];
        }
    }

    for(i = 0; i < q; i++)
        cout << queries[i] << endl;
}