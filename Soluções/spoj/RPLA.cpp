/*
Problema: Answer the boss!
Categorias:
	graphs > topological sorting
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_V 1001
#define MAX_A 10001

using namespace std;

int grau[MAX_V];
int in_degree[MAX_V];
int adj[MAX_V][MAX_A];

void init(){
    memset(grau, 0, sizeof(grau));
    memset(in_degree, 0, sizeof(in_degree));
}

typedef struct {
    bool operator()(pair<int,int> const& b1, pair<int,int> const& b2) {
        if (b1.first > b2.first) 
            return true;
        else if (b1.first == b2.first) {
            return b1.second > b2.second;
        } else return false;
    }
} Comparator;

void aresta(int a, int b){
    adj[a][grau[a]] = b;
    grau[a]++;
    in_degree[b]++;
}

vector<pair<int, int>> L;
void topological_sort(int n){
    priority_queue<pair<int,int>, vector<pair<int,int> >, Comparator> z;
    int v, w;
    pair<int, int> par;
    int rank = 1;
    L.clear();
    for(v = 0; v < n; v++){
        if (in_degree[v] == 0)
            z.push({rank, v});
    }
    rank++;
    while(!z.empty()){
        par = z.top(); z.pop();
        L.push_back(par);
        v = par.second;
        rank = par.first + 1;
        for(int i = 0; i < grau[v]; i++){
            w = adj[v][i];
            in_degree[w]--;
            if(!in_degree[w])
                z.push({rank, w});
        }
    }
}

int main()
{
    int t, n, m, a, b, k, i;
    cin >> t;
    for(k = 1; k <= t; k++){
        cin >> n >> m;
        init();
        for(i = 0; i < m; i++){
            cin >> a >> b;
            aresta(b,a);
        }
        topological_sort(n);
        cout << "Scenario #" << k << ":" << endl;
        for(i = 0; i < n; i++){
            cout << L[i].first << " " << L[i].second << endl;
        }        
    }
}