/*
Problema: Greedy Merchants
Categorias:
	graphs > shortest path
    graphs > bridges
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_V 100001

using namespace std;

typedef struct{
	int v;	
	int w;	
} TAdj;

vector<TAdj> adj[MAX_V]; 
int d[MAX_V];
int p[MAX_V];
int visitado[MAX_V];
vector<int> tin, low;
int timer;

void aresta(int a, int b) {
    TAdj ed;
    ed.v = b;
    ed.w = 0;
    adj[a].push_back(ed);
    ed.v = a;
	adj[b].push_back(ed);
}

void dfsBridges(int v, int p = -1){
    visitado[v] = true;
    tin[v] = low[v] = timer++;
    int to;
    for (int i = 0; i < adj[v].size(); i++) {
        to = adj[v][i].v;
        if (to == p) continue;
        if (visitado[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfsBridges(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                adj[v][i].w = 1;
                for(int j = 0; j < adj[to].size(); j++){
                    if (adj[to][j].v == v){
                        adj[to][j].w = 1;
                        break;
                    }
                }
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    memset(visitado, 0, sizeof(int)*n);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visitado[i])
            dfsBridges(i);
    }
}

int dijkstra(int inicial, int final, int vertices){
	priority_queue< pair<int, int> > heap; //peso, vértice
	int s, t, tipo;
    int peso;
	
	for(int i = 0; i < vertices; i++)
		d[i] = INT_MAX;
	memset(p, -1, sizeof(int)*vertices);
	
	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
		s = heap.top().second;
        if (s == final)
            break;
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
    return d[final];
}

int main(){
    ios_base::sync_with_stdio(false);	
    cin.tie(NULL);
    int n, m, k, a, b, i;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        aresta(a,b);
    }
    find_bridges(n);
    cin >> k;
    for(i = 0; i < k; i++){
        cin >> a >> b;
        a--; b--;
        cout << dijkstra(a, b, n) << endl;
    }
}