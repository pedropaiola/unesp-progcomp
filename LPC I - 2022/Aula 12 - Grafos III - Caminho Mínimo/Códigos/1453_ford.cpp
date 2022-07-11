/*
Problema: Ford-Bellman
Categorias:
    graphs > shortest path
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAX_V 101
#define MAX_A 10001
#define INF 10000000

using namespace std;

int grau[MAX_V];	
long long int d[MAX_V];		
int p[MAX_V];		

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

bool bellmanFord(int inicial, int n){
    memset(p, -1, sizeof(p));
    for(int i=0; i<n; i++)
        d[i] = INF;
    d[inicial] = 0;
    for(int i=0; i<n; i++){ // todos vertices
        for(int j=0; j<n; j++){ /* todas */
            for(int k=0; k<grau[j]; k++){/* arestas */
                if(d[j] != INF && d[j] + adj[j][k].w < d[adj[j][k].v])
                {
                    d[adj[j][k].v] = d[j] + adj[j][k].w;
                    p[adj[j][k].v] = j;
                }
            }
        }
    }
   /*for(int i=0; i<n; i++)
        for(int j=0; j<grau[i]; j++)
            if(d[adj[i][j].v] > d[i] + adj[i][j].w)
                return false;
    */ //Eh garantido que nao ha ciclo
    return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, a, b, i;
    long long int c;
	cin >> n >> m;
    initGrafo(n);
    for(i = 0; i < m; i++){
        cin >> a >> b >> c;
        aresta(a-1,b-1,c);
    }
    bellmanFord(0, n);
    for(i = 0; i < n; i++){
        if (d[i] == INF)
            cout << "30000 ";
        else
            cout << d[i] << " ";         
    }
    cout << endl;
}