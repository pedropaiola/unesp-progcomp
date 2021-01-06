/*
Problema: Kill the Werewolf
Categorias:
	graphs > max flow
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

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

int n;
int noAux(int i){
    return n + i;
}

int main(){
    int a, b, w ,i, resp;
    int votos[51][2];
    while(cin >> n){
        resp = 0;
        for(i = 1; i <= n; i++)
            cin >> votos[i][0] >> votos[i][1];
        for(w = 1; w <= n; w++){
            int x = 0;  
            int s = 0, t = n + n + 1;
            Dinic grafo(n + n + 2, s, t);

            for(i = 1; i <= n; i++){
                if (votos[i][0] == w || votos[i][1] == w)
                    x++;    //Contabilizando votos no lobisomem
            }

            for(i = 1; i <= n; i++){ //Construindo o grafo baseado nos possíveis votos de cada um
                if (i != w) //O lobisomem é o ultimo a votar, vai escolher sempre quem mais convir
                {
                    grafo.add_edge(s, i, 1); //Cada pessoa só tem direito a UM voto
                    //Em quem a pessoa i pode votar?
                    if (votos[i][0] != w && votos[i][1] != w) //Se ela pode votar no lobisomem, ela já votou
                    {
                        grafo.add_edge(i, noAux(votos[i][0]), 1);
                        grafo.add_edge(i, noAux(votos[i][1]), 1);
                    }
                    //A pessoa pode receber no máximo x-1 votos, do contrário o lobisomem ganha.
                    //PORÉM o lobo está de fora do grafo, então se ela pode receber voto do lobo, só pode receber x-2
                    if (votos[w][0] == i || votos[w][1] == i)
                        grafo.add_edge(noAux(i), t, x-2);
                    else
                        grafo.add_edge(noAux(i), t, x-1);
                }
            }
            //Se o lobo recebeu x votos, está faltando n - x - 1 (excluindo o voto do lobo)
            //Logo, o fluxo máximo deve ser exatamente n - x - 1, do contrário, não conseguimos
            //fazer com que todos votassem respeitando as restrições
            if (grafo.flow() < n - x - 1)
                resp++; 
        }
        cout << resp << endl;
    }
}