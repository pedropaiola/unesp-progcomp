#include<bits/stdc++.h>
#define MAX_V 10000
#define MAX_A 100000

using namespace std;

typedef struct{
	int v;
	long long w;
} TAdj;

vector<TAdj> adj[MAX_V+1]; //Grafo
int p[MAX_V+1]; 
int d[MAX_V+1];
int visited[MAX_V+1];


void initGrafo(int qtdeVertices) {
	for(int i = 0; i < qtdeVertices; i++)
		adj[i].clear();
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


long long prim(int inicio, int n){
	long long total = 0;
	priority_queue< pair<long long, int> > heap;
	int s, t, arc;
	for(int i=0; i < n; i++)
		d[i] = INT_MAX;
	memset(p, -1, sizeof(p));
	memset(visited, 0, sizeof(visited));
	heap.push(make_pair(d[inicio] = 0, inicio));
	total = 0;
	while(!heap.empty()){
		s = heap.top().second;
		heap.pop();
		if(!visited[s])
			total += d[s];
		visited[s] = 1;
		for(int i=0; i < adj[s].size(); i++){
			t = adj[s][i].v;
			arc = adj[s][i].w;
			if(d[t] > arc && !visited[t]){
				d[t] = arc;
				p[t] = s;
				heap.push(make_pair(-d[t], t));
			}
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
	cout << prim(1,n+1) << endl;
}
