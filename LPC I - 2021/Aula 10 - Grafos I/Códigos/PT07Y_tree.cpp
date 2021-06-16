/*
Problema: Is it a tree
Categorias:
    graphs > dfs
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXV 10000

using namespace std;

vector<int> adj[MAXV];
int visitado[MAXV];

void initGrafo(int qtdeVertices){
    memset(visitado, 0, sizeof(visitado));
    for(int i = 0; i < qtdeVertices; i++){
        adj[i].clear();
    }
}

void aresta(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int cont = 0;
bool dfs(int u, int pai){
    cont++;
    visitado[u] = 1;
    for(auto v : adj[u]){
        if (!visitado[v])
        {
            if (!dfs(v, u))
                return false;
        }
        else if (v != pai)
            return false;
    } 
    return true;
}

int main(){
    int n, m, x, y, i;
    cin >> n >> m;
    initGrafo(n);
    for(i = 0; i < m; i++){
        cin >> x >> y;
        aresta(x-1, y-1);
    }
    cout << (dfs(0, -1) && cont == n ? "YES" : "NO") << endl;
}