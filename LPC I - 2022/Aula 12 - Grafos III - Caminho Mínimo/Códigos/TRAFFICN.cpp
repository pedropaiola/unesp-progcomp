/*
Problema: Traffic Network
Categorias:
    graphs > shortest path
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAX_V 10000

using namespace std;
int d[MAX_V];			//distância
int p[MAX_V];			//pai do vértice

typedef struct{
	int v;	//vértice
	int w;	//peso
} TAdj;

vector<TAdj> adj[MAX_V];

//inserção de aresta
void aresta(int a, int b, int w){
    TAdj aux;
    aux.v = b;
    aux.w = w;
	adj[a].push_back(aux);
}

void initGraph(int n){
    for(int i = 0; i < n; i++)
        adj[i].clear();
}

int dijkstra(int inicial, int final, int vertices){
	priority_queue< pair<int, int> > heap; //peso, vértice
	int s, t, peso;
	
	for(int i = 0; i < vertices; i++)
		d[i] = INT_MAX;
	memset(p, -1, sizeof(int)*vertices);
	
	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
		s = heap.top().second;
        if (s == final)
            return d[s];
		heap.pop();
		for(int i = 0; i < adj[s].size(); i++){
			t = adj[s][i].v;
			peso = adj[s][i].w;
			if (d[s] + peso < d[t]){
				d[t] = d[s] + peso;
				p[t] = s;
				heap.push(make_pair(-d[t], t));
			}
		}
	}
    return INT_MAX;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int c, n, m, k, s, t;
    int a, b, w;
    int i;

    cin >> c;
    while(c--){
        cin >> n >> m >> k >> s >> t;
        s--; t--;
        initGraph(n);

        for(i = 0; i < m; i++){
            cin >> a >> b >> w;
            aresta(a-1, b-1, w);
        }

        int dist = INT_MAX;
        for(i = 0; i < k; i++){
            cin >> a >> b >> w;
            aresta(a-1, b-1, w);
            aresta(b-1, a-1, w);
            dist = min(dist, dijkstra(s, t, n));
            adj[a-1].pop_back();
            adj[b-1].pop_back();
        }
        if (dist == INT_MAX)
            cout << "-1" << endl;
        else
            cout << dist << endl;
    }
}