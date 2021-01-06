/*
Problema: Unique Path
Categorias:
	graphs > bridges
Dificuldade: medio
Descricao:
Dica: https://cp-algorithms.com/graph/bridge-searching.html
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_V 10000

using namespace std;

vector<int> adj[MAX_V]; 
map<pair<int, int>, bool> isBridge;
int visitado[MAX_V];
vector<int> tin, low;
bool excluido[MAX_V];
int timer;

void initGrafo(int qtdeVertices) {
	for(int i = 0; i < qtdeVertices; i++){
		adj[i].clear();
        visitado[i] = 0;
        excluido[i] = false;
    }
    isBridge.clear();
}

void aresta(int a, int b) {
    adj[a].push_back(b);
	adj[b].push_back(a);
}

void dfsBridges(int v, int p = -1){
    visitado[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visitado[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfsBridges(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                isBridge[make_pair(v,to)] = true;
                isBridge[make_pair(to,v)] = true;
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

    //Excluindo vértices que não possuem apenas pontes
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (int)adj[i].size(); j++){
            if (!isBridge.count(make_pair(i, adj[i][j])))
            {
                excluido[i] = true;
                break;
            }
        }
    }
}

//Função para contar nós em uma componente conexa
int contaNos(int no){
    if (visitado[no] || excluido[no])
        return 0;
    int cont = 1;
    visitado[no] = 1;
    for(int i = 0; i < (int)adj[no].size(); i++)
        cont += contaNos(adj[no][i]);
    return cont;
}

//Ajudando a debugar
void imprimirGrafo(int n){
    for(int i = 0; i < n; i++){
        if (excluido[i])
            continue;
        cout << i + 1 << ": ";
        for(int j = 0; j < (int)adj[i].size(); j++){
            if (excluido[adj[i][j]])
                continue;
            cout << adj[i][j] + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(false);	
    cin.tie(NULL);
    int t, i, c, n, m, a, b;
    cin >> t;
    for(c = 1; c <= t; c++){
        cin >> n >> m;
        initGrafo(n);
        for(i = 0; i < m; i++){
            cin >> a >> b;
            aresta(a - 1, b - 1);
        }
        
        find_bridges(n);

        memset(visitado, 0, sizeof(int)*n);
        int qtdePares = 0;
        for(i = 0; i < n; i++)
        {
            a = contaNos(i);
            qtdePares += a*(a-1)/2;
        }
        cout << "Case #" << c << ": " << qtdePares << endl;
    }
}