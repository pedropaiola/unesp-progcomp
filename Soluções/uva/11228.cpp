/*
Problema: Transportation System
Categorias:
    graphs > minimum spanning tree (MST)
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_V 1000
#define MAX_A 500000

using namespace std;

typedef struct{
	int u, v;
	double w;
} TAdj;

pair<int, int> coord[MAX_V];
TAdj adj[MAX_A];
TAdj mst[MAX_A];
int p[MAX_V];
int nro_arestas, posMst;
int states;
double total_road, total_rail;
	
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

void kruskal(int r){
	int u, v, u_set, v_set;
	posMst = 0;
	total_road = 0;
    total_rail = 0;
    states = 1;
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
			if (adj[i].w > r){
                total_rail += adj[i].w;
                states++;
            }
            else
                total_road += adj[i].w;
		}
	}
}

double dist(int v, int u){
    return sqrt((double)(coord[v].first - coord[u].first)*(coord[v].first - coord[u].first) +
                (coord[v].second - coord[u].second)*(coord[v].second - coord[u].second));
}

int main(){
    int t, k, n, r, i, j;
    cin >> t;
    for(k = 1; k <= t; k++){
        cin >> n >> r;
        initGraph();
        for(i = 0; i < n; i++){
            cin >> coord[i].first >> coord[i].second;
            for(j = 0; j < i; j++)
                aresta(i, j, dist(i, j));
        }
        kruskal(r);
        cout << "Case #" << k << ": " << states << " " << round(total_road) << " " << round(total_rail) << endl;
    }
}