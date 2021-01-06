/*
Problema: The Two Routes
Categorias:
	graphs > bfs
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAX_V 400
#define BUS 0
#define TRAIN 1

using namespace std;

int grafo[MAX_V][MAX_V];

void initGrafo(){
    memset(grafo, 0, sizeof(int)*MAX_V*MAX_V);
}

int visitado[MAX_V];
int d[MAX_V];
int bfs(int inicio, int n, int modo)
{
    int s, t;
    queue<int> Q;
    memset(visitado, 0, MAX_V);
    d[inicio] = 0;
    visitado[inicio] = 1;
    Q.push(inicio);
    int fim = n - 1;

    //cout << (modo ? "TRAIN:" : "BUS:") << endl;

	while(!Q.empty()){
        s = Q.front();    
        if (s == fim)
        	break;
		Q.pop();
        for(int i = 0; i < n; i++){
            if (grafo[s][i] == modo && visitado[i] == 0){
                //cout << "(" << s + 1 << ", " << i + 1 << ") ";
                visitado[i] = 1;
                d[i] = d[s] + 1;
                Q.push(i);
            }
        }
    }
    //cout << endl;
    if (visitado[fim])
        return d[fim];
    return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u, v;
    initGrafo();

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        grafo[u-1][v-1] = TRAIN;
        grafo[v-1][u-1] = TRAIN;
    }

    int tempo;
    if (grafo[0][n-1] == TRAIN){
        tempo = bfs(0, n, BUS);
        if (tempo != -1)
            tempo = max(1, tempo);
    }
    else
    {
        tempo = bfs(0, n, TRAIN);
        if (tempo != -1)
            tempo = max(1, tempo);
    }
    cout << tempo << endl;
}