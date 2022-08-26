#include<bits/stdc++.h>
#define ll long long int
#define MAXN 151
#define MAXK 15

ll g[MAXN][MAXN];
ll gc[MAXK][MAXK];
ll d[MAXN][MAXN];
bool marcado[MAXN];

using namespace std;

void aresta(int u, int v, ll w){
    g[u][v] = w;
    g[v][u] = w;
}

void dijkstra(int u, int n){
    //Calcula a menor distância de u até todos os outros vértices
    //Mas SEM passar pelos vértices marcados
    int i, j, k;
    priority_queue<pair<int,int> > heap;
    int s, t;
    ll peso;

    for(int i = 0; i < n; i++)
        d[u][i] = LLONG_MAX;
    
    heap.push({d[u][u] = 0, u});
    while (!heap.empty())
    {
        s = heap.top().second;
        heap.pop();
        for(t = 0; t < n; t++){
            peso = g[s][t];
            if (peso == -1)
                continue;
            if (d[u][s] + peso < d[u][t]){
                d[u][t] = d[u][s] + peso;
                if (!marcado[t])
                    heap.push({-d[u][t], t});
            }
        }        
    }
}

void compactar_grafo(int n, vector<int> pontos, int k){
    int i, j;
    int u, v;
    for(i = 0; i < k; i++){
        u = pontos[i];
        for(j = 0; j < k; j++){
            v = pontos[j];
            if (u == v)
                gc[i][j] = 0;
            else
                gc[i][j] = d[u][v];
        }
    }
}

ll memo[MAXK][1 << MAXK];
int parent[MAXK][1 << MAXK];

ll tsp(int i, int mask, int k){
    if (mask == ((1 << k) - 1))
        return gc[i][0]; //Custo de voltar para a cidade 0
    if (memo[i][mask] != -1)
        return memo[i][mask];
    
    ll res = INT_MAX;
    ll aux;
    for(int j = 0; j < k; j++){
        if (mask & (1 << j))
            continue;
        aux = tsp(j, mask | (1 << j), k) + gc[i][j];
        if (aux < res){
            res = aux;
            parent[i][mask] = j;
        }
    }
    return memo[i][mask] = res;
}



int main(){
    int n, m, k, u, v, i;
    ll w;
    vector<int> pontos;
    memset(g, -1, sizeof(g));

    cin >> n >> m >> k;
    for(i = 0; i < m; i++){
        cin >> u >> v >> w;
        aresta(u-1, v-1, w);
    }
    memset(marcado, false, sizeof(marcado));
    for(i = 0; i < k; i++){
        cin >> u;
        pontos.push_back(u-1);
        marcado[u-1] = true;
    }

    for(auto x : pontos)
        dijkstra(x, n);
    compactar_grafo(n, pontos, k);
    
    /*
    //Imprimindo grafo compactado
    for(i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
            cout << gc[i][j] << " ";
        cout << endl;
    }
    */
    
    memset(memo, -1, sizeof(memo));
    memset(parent, -1, sizeof(parent));
    ll res = tsp(0, 1, k);
    cout << res << "\n";

    /*
    //Imprimir caminho do caixeiro viajante
    int cur_node = 0, cur_mask = 1;
    do{
        cout << cur_node << " ";
        cur_node = parent[cur_node][cur_mask];
        cur_mask = cur_mask | (1 << cur_node);
    } while (cur_node != -1);
    */
}