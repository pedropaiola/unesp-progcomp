/*
Problema: Ada and Trip
Categorias:
    graphs > shortest path
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAX_V 500000

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
	
    aux.v = a;
    adj[b].push_back(aux);
}

int dijkstra(int inicial, int vertices){
	priority_queue< pair<int, int> > heap; //peso, vértice
	int s, t, peso;
    int maxD = 0;
	
	for(int i = 0; i < vertices; i++)
		d[i] = 20000000;
	memset(p, -1, sizeof(int)*vertices);
	
	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
		s = heap.top().second;
		heap.pop();
        maxD = max(maxD, d[s]);
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
    return maxD;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, q, i, j, a, b, w, dist, cont;
    
    cin >> n >> m >> q;
    for(i = 0; i < m; i++){
        cin >> a >> b >> w;
        aresta(a, b, w);
    }

    for(i = 0; i < q; i++){
        cin >> a;
        dist = dijkstra(a, n);
        cont = 0;
        for(j = 0; j < n; j++)
            if (d[j] == dist)
                cont++;
        cout << dist << " " << cont << endl;
    }
}