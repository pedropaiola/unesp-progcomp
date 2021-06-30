/*
Problema: Expensive subway
Categorias:
    graphs > minimum spanning tree (MST)
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/

#include<bits/stdc++.h>
#define MAX_V 400
#define MAX_A 79800

using namespace std;

typedef struct{
	int v;
	long long w;
} TAdj;

vector<TAdj> adj[MAX_V+1]; //Grafo
map<string, int> cidades;
int p[MAX_V+1]; 
int d[MAX_V+1];
int visited[MAX_V+1];
int estacoesAtingidas;

//int idCidade(string c){
//    if (cidades.count(c))
//        return cidades[c];
//    return cidades[c] = total_cidades++;
//}

void initGrafo(int qtdeVertices) {
    cidades.clear();
	for(int i = 0; i < qtdeVertices; i++)
		adj[i].clear();
}
	
void aresta(string cidadeA, string cidadeB, long long w) {
    int a = cidades[cidadeA];
    int b = cidades[cidadeB];

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
    estacoesAtingidas = 0;
	while(!heap.empty()){
		s = heap.top().second;
		heap.pop();
		if(!visited[s]){
			total += d[s];
            estacoesAtingidas++;
        }
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

int main(){
    int n, m, i, w;
    string cA, cB;
    while(true){
        cin >> n >> m;
        if (n == 0)
            break;
        initGrafo(n);
        for(i = 0; i < n; i++){
            cin >> cA;
            cidades[cA] = i;
        }
        for(i = 0; i < m; i++){
            cin >> cA >> cB >> w;
            aresta(cA, cB, w);
        }
        cin >> cA;
        w = prim(cidades[cA], n);
        if (estacoesAtingidas == n)
            cout << w << endl;
        else
            cout << "Impossible" << endl;
    }
}