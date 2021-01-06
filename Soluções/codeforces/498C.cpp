/*
Problema: Array and Operations
Categorias:
	graphs > specials > bipartite > matching
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define NIL 0 
#define INF INT_MAX 

using namespace std;

class BGraph
{
    int m, n;
    std::list<int> *adj;
    int *pair_u, *pair_v, *dist;

public:
    BGraph(int m, int n);     
    void addEdge(int u, int v); 

    bool bfs();
    bool dfs(int u);
    int hopcroftKarpAlgorithm();
};

int BGraph::hopcroftKarpAlgorithm()
{
    pair_u = new int[m + 1];
    pair_v = new int[n + 1];
    dist = new int[m + 1];

    for (int u = 0; u <= m; u++)
        pair_u[u] = NIL;
    for (int v = 0; v <= n; v++)
        pair_v[v] = NIL;

    int result = 0;

    while (bfs())
    {
        for (int u = 1; u <= m; u++)
            if (pair_u[u] == NIL && dfs(u))
                result++;
    }
    return result;
}

bool BGraph::bfs()
{
    std::queue<int> q; 
    for (int u = 1; u <= m; u++)
    {
        if (pair_u[u] == NIL)
        {
            dist[u] = 0;
            q.push(u);
        }
        else
            dist[u] = INF;
    }
    dist[NIL] = INF;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dist[u] < dist[NIL])
        {
            std::list<int>::iterator it;
            for (it = adj[u].begin(); it != adj[u].end(); ++it)
            {
                int v = *it;
                if (dist[pair_v[v]] == INF)
                {
                    dist[pair_v[v]] = dist[u] + 1;
                    q.push(pair_v[v]);
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool BGraph::dfs(int u)
{
    if (u != NIL)
    {
        std::list<int>::iterator it;
        for (it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            int v = *it;
            if (dist[pair_v[v]] == dist[u] + 1)
            {
                if (dfs(pair_v[v]) == true)
                { 
                    pair_v[v] = u;
                    pair_u[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

BGraph::BGraph(int m, int n)
{
    this->m = m;
    this->n = n;
    adj = new std::list<int>[m + 1];
}

void BGraph::addEdge(int u, int v)
{
    adj[u].push_back(v); 
}

vector<int> fatores(int x){
    vector<int> fat;
    for(int i = 2; i * i <= x; i++){
        while (x % i == 0){
            x /= i;
            fat.push_back(i);
        }
    }
    if (x != 1){
        fat.push_back(x);
    }
    return fat;
}


int main(){
    int n, m, i, l, r;
    int a[101];
    int indIni[101];
    int qtdeVL, qtdeVR;
    map<int, vector<int> > fats;
    qtdeVL = qtdeVR = 0;

    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> a[i];
        if (!fats.count(a[i]))
            fats[a[i]] = fatores(a[i]);
        if (i % 2)
        {
            indIni[i] = qtdeVR + 1;
            qtdeVR += fats[a[i]].size();
        }
        else
        {    
            indIni[i] = qtdeVL + 1;
            qtdeVL += fats[a[i]].size();
        }
    }

    BGraph g(qtdeVL+1, qtdeVR+1);
    for(i = 0; i < m; i++){
        cin >> l >> r;
        if (l % 2)
            swap(l, r);
        vector<int> fL = fats[a[l]];
        vector<int> fR = fats[a[r]];
        for(int li = 0; li < fL.size(); li++){
            for(int rj = 0; rj < fR.size(); rj++){
                if (fL[li] != fR[rj])
                    continue;
                g.addEdge(indIni[l] + li, indIni[r] + rj);
            }
        }
    }
    cout << g.hopcroftKarpAlgorithm() << endl;
}