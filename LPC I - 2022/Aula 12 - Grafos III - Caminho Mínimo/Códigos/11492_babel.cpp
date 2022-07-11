/*
Problema: Babel
Categorias:
    graphs > shortest path
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>
#define MAX_V 4005
#define MAX_L 27

using namespace std;

int d[MAX_V][MAX_L];			
map<string, int> indMap;
int cont;

typedef struct{
	int v;
    int l;	
	int w;
} TAdj;
vector<TAdj> adj[MAX_V][MAX_L];

void init(){
    for(int i = 0; i < MAX_V; i++)
        for(int j = 0; j < MAX_L; j++)
            adj[i][j].clear();
    indMap.clear();
    cont = 0;
}

void aresta(int a, int la, int b, int lb, int w){
	TAdj aux;
    aux.v = b;
    aux.l = lb;
    aux.w = w;
    adj[a][la].push_back(aux);
    //cout << "(" << a << ", " << la << ") " << w << " (" << b << ", " << lb << ")" << endl;
}

int ind(string s){
    if (!indMap.count(s))
    {
        indMap[s] = cont++;
    }
    return indMap[s];
}

int indL(string p){
    return (int)(p[0] - 'a');
}

void aresta(string lang1, string lang2, string palavra){
    int v1, v2;
    v1 = ind(lang1);
    v2 = ind(lang2);
    if (v2 < v1) swap(v1,v2);
    if (v1 == 0) //v1 é a origem
    {
        if (v2 == 1) //v2 é o destino
            aresta(v1, 0, v2, 0, palavra.size());
        else
            aresta(v1, 0, v2, indL(palavra), palavra.size());
    }
    else if (v1 == 1)
    {
        for(int i = 0; i < MAX_L; i++){
            if (i == indL(palavra))
                continue;
            aresta(v2, i, v1, 0, palavra.size());
        }
    }
    else if (v2 == 1)
    {
        for(int i = 0; i < MAX_L; i++){
            if (i == indL(palavra))
                continue;
            aresta(v1, i, v2, 0, palavra.size());
        }
    }
    else
    {
        //v1 e v2 não são nem origem nem destino
        for(int i = 0; i < MAX_L; i++){    
            if (i == indL(palavra))
                continue;
            aresta(v1, i, v2, indL(palavra), palavra.size()); //de v1/i -> v2/l
            aresta(v2, i, v1, indL(palavra), palavra.size()); //de v2/i -> v1/l
        }
    }
}


int dijkstra(){
	priority_queue< tuple<int, int, int> > heap; //peso, vertice, letra
	int s, sl, t, tl, peso;
	for(int i = 0; i < MAX_V; i++)
        for(int j = 0; j < MAX_L; j++)
		    d[i][j] = INT_MAX;

	heap.push({d[0][0] = 0, 0, 0});
	while(!heap.empty()){
		s = get<1>(heap.top());
        sl = get<2>(heap.top());
		heap.pop();
        if (s == 1) //destino
            return d[1][0];
		for(int i = 0; i < adj[s][sl].size(); i++){
			t = adj[s][sl][i].v;
            tl = adj[s][sl][i].l;
			peso = adj[s][sl][i].w;
			if (d[s][sl] + peso < d[t][tl]){
				d[t][tl] = d[s][sl] + peso;
				heap.push({-d[t][tl], t, tl});
			}
		}
	}
    return -1;
}

int main(){
    int m, i, resp;
    string l1, l2, p;
    while(1){
        cin >> m;
        if (m == 0)
            break;
        init();
        cin >> l1 >> l2;
        ind(l1);    //determinar origem
        ind(l2);    //determinar destino
        for(i = 0; i < m; i++){
            cin >> l1 >> l2 >> p;
            aresta(l1, l2, p);
        }
        resp = dijkstra();
        if (resp == -1)
            cout << "impossivel" << endl;
        else
            cout << resp << endl;        
    }
}