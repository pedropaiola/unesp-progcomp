/*
Problema: Ordering Tasks
Categorias:
	graphs > topological sorting
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_V 101
#define MAX_A 10001

using namespace std;

int grau[MAX_V];
int in_degree[MAX_V];
int adj[MAX_V][MAX_A];

void init(){
    memset(grau, 0, sizeof(grau));
    memset(in_degree, 0, sizeof(in_degree));
}

void aresta(int a, int b){
    adj[a][grau[a]] = b;
    grau[a]++;
    in_degree[b]++;
}

vector<int> L;
void topological_sort(int n){
    queue<int> z;
    int v, w;
    L.clear();
    for(v = 1; v <= n; v++){
        if (in_degree[v] == 0)
            z.push(v);
    }
    while(!z.empty()){
        v = z.front(); z.pop();
        L.push_back(v);
        for(int i = 0; i < grau[v]; i++){
            w = adj[v][i];
            in_degree[w]--;
            if(!in_degree[w])
                z.push(w);
        }
    }
}

int main()
{
    int n, m, u, d, i;
    while(1){
        cin >> n >> m;
        if (n == 0)
            break;
        init();
        for(i = 0; i < m; i++){
            cin >> d >> u;
            aresta(d, u);
        }
        topological_sort(n);
        cout << L[0];
        for(i = 1; i < n; i++)
            cout << " " << L[i];
        cout << endl;
    }
}