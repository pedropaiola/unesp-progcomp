/*
Problema: Atul and Aastha Chronicles 1
Categorias:
    graphs > bfs
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXV 10000

using namespace std;

vector<int> adj[MAXV];
int d[MAXV];
int visitado[MAXV];

void initGrafo(int qtdeVertices){
    for(int i = 0; i < qtdeVertices; i++)
        adj[i].clear();
}

void aresta(int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int bfs(int inicio, int fim){
    int s, t;
    queue<int> Q;

    memset(visitado, 0, sizeof(visitado));
    d[inicio] = 0;
    visitado[inicio] = 1;
    Q.push(inicio);

    while(!Q.empty()){
        s = Q.front();
        Q.pop();
        if (s == fim)
            return d[s];
        for(auto t : adj[s]){
            if (!visitado[t]){
                visitado[t] = 1;
                d[t] = d[s] + 1;
                Q.push(t);
            }
        }
    }
    return -1;
}

int main(){
    int t, n, m, x, y, i;
    cin >> t;
    while(t--){
        cin >> n >> m;
        initGrafo(n);
        for(i = 0; i < m; i++){
            cin >> x >> y;
            aresta(x-1, y-1);
        }
        cout << bfs(0, n-1) << endl;
    }
}

