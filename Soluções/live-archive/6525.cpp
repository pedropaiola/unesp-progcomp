/*
Problema: A - Attacking rooks
Categorias:
	graphs > specials > bipartite > matching
    maratona > nacional 2013
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h> 
using namespace std; 
#define NIL 0 
#define INF INT_MAX 
  
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
  
int main() 
{ 
    int n, nL, nC, i, j;
    int matL[100][100];
    int matC[100][100];
    string tab[100];
    while(cin >> n){
        for(i = 0; i < n; i++)
            cin >> tab[i];
        //Definindo os vértices que representaração cada partição de linha
        nL = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if (tab[i][j] == '.')
                    matL[i][j] = nL;
                else
                {
                    matL[i][j] = -1;
                    nL++;
                }
            }
            nL++;
        }
        //Definindo os vértices que representaração cada partição de coluna
        nC = 0;
        for(j = 0; j < n; j++){
            for(i = 0; i < n; i++){
                if (tab[i][j] == '.')
                    matC[i][j] = nC;
                else
                {
                    matC[i][j] = -1;
                    nC++;
                }
            }
            nC++;
        }
        //Criando grafo bipartido
        BGraph g(nL, nC);
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if (matL[i][j] != -1){
                    g.addEdge(matL[i][j] + 1, matC[i][j] + 1);
                }
            }
        }
        cout << g.hopcroftKarpAlgorithm() << endl;
    }
} 
