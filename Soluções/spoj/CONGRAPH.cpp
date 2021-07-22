/*
Problema: Connected country
Categorias:
    graphs > dfs
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXV 800000

using namespace std;

vector<int> adj[MAXV];
int visitado[MAXV];

void initGrafo(int qtdeVertices){
    for(int i = 0; i < qtdeVertices; i++){
        adj[i].clear();
        visitado[i] = 0;
    }
}

void aresta(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs(int u){
    visitado[u] = 1;
    for(auto v : adj[u]){
        if (!visitado[v])
            dfs(v);
    } 
}

int main(){
    int n, m, x, y, i;
    cin >> n >> m;
    initGrafo(n);
    for(i = 0; i < m; i++){
        cin >> x >> y;
        aresta(x, y);
    }
    int qtdeComp = 0;
    for(i = 0; i < n; i++){
        if (!visitado[i])
        {
            dfs(i);
            qtdeComp++;
        }
    }
    cout << qtdeComp - 1 << endl;
}