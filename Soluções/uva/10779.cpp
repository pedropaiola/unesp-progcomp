/*
Problema: Collectors Problem
Categorias:
	graphs > max flow
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 30

using namespace std;

struct FlowEdge {
    int v, u;
    int cap, flow = 0;
    FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const int flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, int cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    int dfs(int v, int pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    int flow() {
        int f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int n, m;
int amigo(int i){
    return m + i;
}

int main(){
    int t, q, i, j, x;
    cin >> t;
    for(int k = 1; k <= t; k++){
        int qtdeStickers[MAXN][MAXN] = {0};
        cin >> n >> m;
        for(i = 1; i <= n; i++){
            cin >> q;
            for(j = 1; j <= q; j++){
                cin >> x;
                qtdeStickers[i][x]++;
            }
        }
        //0 = fonte
        //1 - m: stickers de Bob
        //m + 1 ... m + n: amigos de Bob 
        //m + n + 1: sumidouro
        int s = 0; 
        int t = n + m + 1;
        Dinic grafo(m+n+2, s, t);
        for(i = 1; i <= m; i++){
            grafo.add_edge(s, i, qtdeStickers[1][i]);   //Quanto Bob tem de cada sticker inicialmente
            grafo.add_edge(i, t, 1);            //Queremos que ele tenha um de cada no final (ou o mais próximo disso)
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                //Se a pessoa j tem mais de um sticker i, então ela tem capacidade de fornecer para Bob
                if (qtdeStickers[j][i] >= 2)
                {
                    grafo.add_edge(amigo(j), i, qtdeStickers[j][i] - 1);
                }
                else if (qtdeStickers[j][i] == 0) //Agora se ela não tem nenhum, então Bob tem a capacidade de trocar com ela
                {
                    grafo.add_edge(i, amigo(j), 1);
                }  
            }
        }
        cout << "Case #" << k << ": " << grafo.flow() << endl;
    }
}