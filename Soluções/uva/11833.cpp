/*
Problema: Route Change
Categorias:
	graphs > shortest path
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola / Giulia
*/
#include <bits/stdc++.h>
#define MAX_V 250
#define MAX_A 62500

using namespace std;

int grau[MAX_V];		//n�mero de arestas do v�rtice
int d[MAX_V];			//dist�ncia
int p[MAX_V];			//pai do v�rtice

typedef struct{
	int v;	//v�rtice
	int w;	//peso
} TAdj;
TAdj adj[MAX_V][MAX_A];

//inser��o de aresta
void aresta(int a, int b, int w){
	adj[a][ grau[a] ].v = b;
	adj[a][ grau[a] ].w = w;
	grau[a]++;
}

void initGrafo(int vertices, int arestas){
	memset(grau, 0, sizeof(int)*vertices);
	memset(p,-1, sizeof(int)*vertices);
}

void dijkstra(int inicial, int vertices){
	priority_queue< pair<int, int> > heap; //peso, v�rtice
	int s, t, peso;
	
	for(int i = 0; i < vertices; i++)
		d[i] = 20000000;
	memset(p, -1, sizeof(int)*vertices);
	
	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
		s = heap.top().second;
		heap.pop();
		for(int i = 0; i < grau[s]; i++){
			t = adj[s][i].v;
			peso = adj[s][i].w;
			if (d[s] + peso < d[t]){
				d[t] = d[s] + peso;
				p[t] = s;
				heap.push(make_pair(-d[t], t));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, c, k, u, v, peso, i;
	while(1){
		cin >> n >> m >> c >> k;
		if (n == 0)
			break;
		initGrafo(n, m);
		for(i = 0; i < m; i++){
			cin >> u >> v >> peso;
			if (u >= c && v >= c)
			{
				//se u e v n�o estiverem na rota, criamos as arestas (u,v) e (v,u)
				aresta(u,v,peso);
				aresta(v,u,peso);
			} 
			else if (u < c && v < c) 
			{
				//se u e v estiverem na rota, criamos uma aresta apenas se forem consecutivas
				if (u + 1 == v)
					aresta(u,v,peso);
				else if (v + 1 == u)
					aresta(v,u,peso);
			} 
			else 
			{
				//se uma das arestas estiver na rota e a outra n�o, criamos uma aresta
				//do v�rtice fora da rota para o v�rtice na rota
				if (v < c)
					aresta(u,v,peso);
				else
					aresta(v,u,peso);
			}
		}
		dijkstra(k, n);
		cout << d[c-1] << endl;
	}
}
