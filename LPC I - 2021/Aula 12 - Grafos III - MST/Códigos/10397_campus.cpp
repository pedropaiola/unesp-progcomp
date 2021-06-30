/*
Problema: Connect the Campus
Categorias:
    graphs > minimum spanning tree (MST)
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_V 750
#define MAX_A 300000

using namespace std;

typedef struct{
	int u, v;
	double w;
} TAdj;

pair<int, int> coord[MAX_V];
TAdj adj[MAX_A];
TAdj mst[MAX_A]; //armazena a MST
int p[MAX_V];
int nro_arestas, posMst;
double total;
	
void initGraph(){
    nro_arestas = 0;
}

void aresta(int u, int v, double w)
{
	adj[nro_arestas].u = u;
	adj[nro_arestas].v = v;
	adj[nro_arestas].w = w;
	nro_arestas++;
}
	
int cmp(const void *a, const void *b){
	TAdj *x, *y;
	x = (TAdj*)a;
	y = (TAdj*)b;
	if(x->w < y->w)
		return -1;
	if(x->w > y->w)
		return 1;
	return 0;
}
	
int findSet(int x){
	if(x != p[x])
		p[x] = findSet(p[x]);
	return p[x];
}

void kruskal(){
	int u, v, u_set, v_set;
	posMst = 0;
	total = 0;
	for(int i=0; i<MAX_V; i++) // todos v�rtices	
		p[i] = i;
	qsort(adj, nro_arestas, sizeof(TAdj), cmp);
	for(int i=0; i<nro_arestas; i++){
		u = adj[i].u; 
		v = adj[i].v;
		u_set = findSet(u);
		v_set = findSet(v);
		if(u_set != v_set){
			p[v_set] = p[u_set];
			mst[posMst++] = adj[i];
			total += adj[i].w;
		}
	}
}

double dist(int v, int u){
    return sqrt((double)(coord[v].first - coord[u].first)*(coord[v].first - coord[u].first) +
                (coord[v].second - coord[u].second)*(coord[v].second - coord[u].second));
}

int main(){
    int n, m, i, j;
    int u, v;
    while(cin >> n){
        initGraph();
        for(i = 0; i < n; i++){
            cin >> coord[i].first >> coord[i].second;
            for(j = 0; j < i; j++)
                aresta(i, j, dist(i, j));
        }
        cin >> m;
        for(i = 0; i < m; i++){
            cin >> u >> v;
            aresta(u-1, v-1, 0); //Uma forma de obrigar a seleção destas arestas
        }
        kruskal();
        printf("%.2f\n", total);
    }
}