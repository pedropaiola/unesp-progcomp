/*
Problema: A Bug's Life
Categorias:
    graphs > dfs
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXV 2001

using namespace std;

vector<int> adj[MAXV];
int cor[MAXV];

void initGrafo(int qtdeVertices){
    for(int i = 0; i < qtdeVertices; i++){
        adj[i].clear();
        cor[i] = -1;
    }
}

void aresta(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool dfs(int u, int cor_atual){
    cor[u] = cor_atual;
    for(auto v : adj[u]){
        if (cor[v] == -1)
        {
            if (!dfs(v, !cor_atual))
                return false;
        }
        else if (cor[v] == cor_atual)
            return false;
    } 
    return true;
}

int main(){
    int t, n, m, a, b;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> m;
        initGrafo(n);
        for(int j = 0; j < m; j++){
            cin >> a >> b;
            aresta(a-1, b-1);
        }
        bool ok = true;
        for(int j = 0; j < n && ok; j++){
            if (cor[j] == -1)
                ok = dfs(j, 0);
        }
        cout << "Scenario #" << i << ":" << endl;
        cout << (ok ? "No suspicious bugs found!" : "Suspicious bugs found!") << endl;
    }
}




