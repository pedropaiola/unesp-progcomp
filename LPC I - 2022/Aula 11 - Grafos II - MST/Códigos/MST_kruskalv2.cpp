#include<bits/stdc++.h>
#define MAX_V 10000
#define MAX_A 100000

using namespace std;

typedef struct{
	int v;
	long long w;
} TAdj;

vector<TAdj> adj[MAX_V+1]; //Grafo
vector<TAdj> mst[MAX_V+1]; //Árvore Geradora Mínima

//Union-find
int dset[MAX_V+1]; 
int tam[MAX_V+1];

void initGrafo(int qtdeVertices) {
	for(int i = 0; i < qtdeVertices; i++)
	{
		adj[i].clear();
		mst[i].clear();
	}
}
	
void aresta(int a, int b, long long w) {
	adj[a].push_back(*(new TAdj()));
	int grau = adj[a].size() - 1;
	adj[a][grau].v = b;
	adj[a][grau].w = w;
	
	adj[b].push_back(*(new TAdj()));
	grau = adj[b].size() - 1;
	adj[b][grau].v = a;
	adj[b][grau].w = w;
}

void arestaMST(int a, int b, long long w) {
	mst[a].push_back(*(new TAdj()));
	int grau = mst[a].size() - 1;
	mst[a][grau].v = b;
	mst[a][grau].w = w;
	
	mst[b].push_back(*(new TAdj()));
	grau = mst[b].size() - 1;
	mst[b][grau].v = a;
	mst[b][grau].w = w;
}
	
int find(int x) {
	if (dset[x] == x || dset[x] == -1) 
		return x;
	else             
		return find(dset[x]);
}

bool same(int x, int y)
{
	return (find(x) == find(y));
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (tam[a] < tam[b]) 
		swap(a, b);
	 
	dset[b] = a;
	tam[a] += tam[b];
}	

long long kruskal(int qtdeVertices){
	int u, v, w, u_set, v_set;
	int i, j;
	long long total = 0;
	priority_queue<tuple<long long, int, int> > heap; //-w, u, v

	for(i = 0; i < qtdeVertices; i++)
	{
		dset[i] = i;
		tam[i] = 1;
	}
	
	for(i = 0; i < qtdeVertices; i++)
		for(j = 0; j < adj[i].size(); j++)
			heap.emplace(-adj[i][j].w, i, adj[i][j].v);
	
	while(!heap.empty()){
		w = -get<0>(heap.top());
		u = get<1>(heap.top()); 
		v = get<2>(heap.top());
		heap.pop();
		if(!same(u, v)){
			merge(u, v);
			arestaMST(u, v, w);
			total += w;
		}
	}
	return total;
}

int main()
{
	int n, m, i, u, v;
	long long w;
	cin >> n >> m;
	for(i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		aresta(u, v, w);
	}
	cout << kruskal(n+1) << endl;
}
