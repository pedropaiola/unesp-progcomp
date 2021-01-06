/*
Problema: Imperial roads
Categorias:
	graphs > minimum spanning tree (MST)
    graphs > specials > tree > lowest common ancestor (LCA)
Dificuldade: dificil
Descricao:
Dica:
Autor: ?
*/
#include<bits/stdc++.h>
#define ll long long int
#define MAXN 100010
#define aresta pair<int, int>

using namespace std;

vector<pair<int,int> > mst_edge[MAXN]; //u -> v, w
priority_queue<pair<int,aresta> > heap; //w, (u,v)
int par[MAXN], lca_par[MAXN][18], cost[MAXN][18], n, m, depth[MAXN];
map<aresta, pair<bool,int> > taken;

void init()
{
    for(int i = 0; i <= n; i++)
        mst_edge[i].clear();
    taken.clear();
}

int parent(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = parent(par[x]);
}

ll kruskal()
{
    ll total = 0;
    while(!heap.empty())
    {
        int w = -heap.top().first;
        int u = heap.top().second.first;
        int v = heap.top().second.second;
        heap.pop();
        int setU = parent(u);
        int setV = parent(v);
        if (setU != setV)
        {
            par[setU] = setV;
            mst_edge[u].push_back({v, w});
            mst_edge[v].push_back({u, w});
            taken[{u, v}] = {true, w};
            total += w;
        }
        else
        {
            taken[{u, v}] = {false, w};
        }
    }
    return total;
}

void dfs(int pai, int u)
{
    for(auto v:mst_edge[u])
    {
        if (v.first == pai)
            continue;
        lca_par[v.first][0] = u;
        cost[v.first][0] = v.second;
        depth[v.first] = depth[u] + 1;
        dfs(u, v.first);
    }
}

void sparse_table()
{
    dfs(-1, 1); //enraizado a árvore em 1
    int times = min(17, (int)log2(n) + 1);
    for(int k=1; k <= times; k++)
    {
        for(int i = 0; i <= n; i++)
        {
            lca_par[i][k] = lca_par[lca_par[i][k-1]][k-1];
            cost[i][k] = max(cost[i][k-1], cost[lca_par[i][k-1]][k-1]);
        }
    }
}

//Aqui vai acontecer a mágina de retornar o peso da aresta a ser tirada do caminho que havia entre u e v
//antes de inserir a aresta (u, v). E claro, a aresta a ser tirada é aresta de maior peso desse caminho
ll lca(int u, int v)
{
    int ans = -1;
    if(depth[u] < depth[v])
        swap(u, v);
    int times = min(17, (int)log2(n) + 1);
    for(int i = times; i >= 0; i--)
    {
        if (depth[lca_par[u][i]] >= depth[v])
        {
            ans = max(ans, cost[u][i]);
            u = lca_par[u][i];
        }
    }
    if(u == v)
        return ans;
    for(int i = times; i >= 0; i--)
    {
        if(lca_par[u][i] != lca_par[v][i])
        {
            ans = max(ans, cost[u][i]);
            ans = max(ans, cost[v][i]);
            u = lca_par[u][i];
            v = lca_par[v][i];
        }
    }
    ans = max(ans, cost[u][0]);
    ans = max(ans, cost[v][0]);
    return ans;
}

int main(){
    while(scanf("%d %d", &n, &m) == 2)
    {
        int u, v, w;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            if (u > v)
                swap(u, v);
            heap.push({-w, {u,v}});
        }
        for(int i = 0; i < MAXN; i++)
            par[i] = i;
        ll custoMST = kruskal();
        sparse_table();
        int q;
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            scanf("%d %d", &u, &v);
            if (u > v)
                swap(u, v);
            auto ed = taken[{u,v}]; 
            if (ed.first)
            {
                printf("%lld\n", custoMST);
            }
            else
            {
                int temp = lca(u, v);
                ll ans = custoMST - temp + ed.second;
                printf("%lld\n", ans);
            }
        }
        init();
    }
}