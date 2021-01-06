/*
Problema: Coins Respawn
Categorias:
	graphs > shortest path
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAX_V 2500
#define MAX_A 5000
#define INF LLONG_MAX

using namespace std;

int grau[MAX_V];	
long long int d[MAX_V];		
int p[MAX_V];	
int visitado[MAX_V];	

typedef struct{
	int v;	
	long long int w;	
} TAdj;
TAdj adj[MAX_V][MAX_A];

void aresta(int a, int b, long long int w){
	adj[a][ grau[a] ].v = b;
	adj[a][ grau[a] ].w = w;
	grau[a]++;
}

void initGrafo(int vertices){
	memset(grau, 0, sizeof(int)*vertices);
	memset(p,-1, sizeof(int)*vertices);
}

void dfs(int v){
    visitado[v] = 1;
    for(int i = 0; i < grau[v]; i++){
        if (!visitado[adj[v][i].v])
            dfs(adj[v][i].v);
    }
}

bool interfere(int v, int n){
    memset(visitado, 0, sizeof(int)*n);
    dfs(v);
    if (visitado[0] || visitado[n-1])
        return true;
    return false;
}

bool bellmanFord(int inicial, int n){
    memset(p, -1, sizeof(p));
    for(int i=0; i<n; i++)
        d[i] = INF;
    d[inicial] = 0;
    for(int i=0; i<n; i++){ // todos vertices
        for(int j=0; j<n; j++){ /* todas */
            if (d[j] == INF)
                continue;
            for(int k=0; k<grau[j]; k++){/* arestas */
                if(d[j] + adj[j][k].w < d[adj[j][k].v])
                {
                    d[adj[j][k].v] = d[j] + adj[j][k].w;
                    p[adj[j][k].v] = j;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        if (d[i] == INF)
            continue;
        for(int j=0; j<grau[i]; j++){
            if(d[adj[i][j].v] > d[i] + adj[i][j].w && interfere(adj[i][j].v, n)) 
                return false;
        }
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, a, b, i;
    long long int c, pv, resp = 0;
	cin >> n >> m >> pv;
    initGrafo(n);
    for(i = 0; i < m; i++){
        cin >> a >> b >> c;
        aresta(a-1,b-1,pv-c);
    }
    if (bellmanFord(0, n))
    {
        cout << max(resp, -d[n-1]) << endl;
    } 
    else
    {
        cout << "-1" << endl;
    }
}
