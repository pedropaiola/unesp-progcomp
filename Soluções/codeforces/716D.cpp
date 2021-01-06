/*
Problema: Complete The Graph
Categorias:
	graphs > shortest path
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX_V 1000
#define VARIAVEL 1
#define CONSTANTE 0
#define ll long long int
#define INFI 1000000000000000000

using namespace std;

typedef struct{
	int v;	
    int tipo;	
} TAdj;

vector<TAdj> adj[MAX_V];
map<pair<int, int>, ll> pesoAresta;
vector<pair<int, int> > arestasVar;
vector<pair<int, int> > arestasOrdem;
map<pair<int, int>, bool> alterado;
map<pair<int, int>, bool> ehVar;
int grau[MAX_V];
ll d[MAX_V];
int p[MAX_V];

void iniciarPeso(int a, int b, ll w){
    pesoAresta[make_pair(a,b)] = w;
    pesoAresta[make_pair(b,a)] = w;
}

void alterarPeso(pair<int, int> ed1, ll w){
    pair<int, int> ed2 = make_pair(ed1.second,ed1.first);
    if (alterado.count(ed1) || alterado.count(ed2))
        return;
    pesoAresta[ed1] = w;
    pesoAresta[ed2] = w;
    alterado[ed1] = true;
    alterado[ed2] = true;
}

void alterarPeso(int a, int b, ll w){
    alterarPeso(make_pair(a,b), w);
}

void aresta(int a, int b, ll w){
    TAdj aux;
    aux.v = b;
    aux.tipo = (w == 0);
    adj[a].push_back(aux);
	grau[a]++;

    aux.v = a;
    adj[b].push_back(aux);
    grau[b]++;

    iniciarPeso(a, b, w);
    if (aux.tipo == VARIAVEL)
    {
        arestasVar.push_back(make_pair(a,b));
        ehVar[make_pair(a,b)] = true;
        ehVar[make_pair(b,a)] = true;
    }
    arestasOrdem.push_back(make_pair(a,b));
}

void initGrafo(int n){
	memset(grau, 0, sizeof(int)*n);
}

ll dijkstra(int inicial, int final, int modo, int vertices){
	priority_queue< pair<ll, int> > heap; //peso, vértice
	int s, t, tipo;
    ll peso;
	
	for(int i = 0; i < vertices; i++)
		d[i] = LLONG_MAX;
	memset(p, -1, sizeof(int)*vertices);
	
	heap.push(make_pair(d[inicial] = 0, inicial));
	while(!heap.empty()){
		s = heap.top().second;
        if (s == final)
            break;
		heap.pop();
		for(int i = 0; i < grau[s]; i++){
			t = adj[s][i].v;
			peso = pesoAresta[make_pair(s,t)];
            tipo = adj[s][i].tipo;
            if (modo == CONSTANTE && tipo == VARIAVEL)
                continue;
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
    int n, m, s, t, i, u, v;
    ll L, w, dist;

    cin >> n >> m >> L >> s >> t;

    for(i = 0; i < m; i++){
        cin >> u >> v >> w;
        aresta(u, v, w);
    }

    //1º) Verificando se, desconsiderando as arestas variáveis, já temos um caminho
    //mínimo com peso menor que L. Nesse caso não tem o que fazer
    dist = dijkstra(s, t, CONSTANTE, n);
    if (dist < L){
        cout << "NO" << endl;
        return 0;
    } 
    if (dist == L){ //Caso bem específico, nem precisaria disso, mas só pra facilitar
        cout << "YES" << endl;
        for(i = 0; i < (int)arestasOrdem.size(); i++){
            w = pesoAresta[arestasOrdem[i]];
            if (w == 0) w = INFI;
            cout << arestasOrdem[i].first << " " << arestasOrdem[i].second << " " << w << endl;
        }
        return 0;
    }

    //2º) Colocando peso 1 (valor mínimo) para todas as arestas variáveis, se agora o caminho mínimo
    //for maior que L, então também não existe caminho possível
    for(i = 0; i < (int)arestasVar.size(); i++){
        alterarPeso(arestasVar[i], 1);
    }
    alterado.clear();
    dist = dijkstra(s, t, VARIAVEL, n);
    if (dist > L){
        cout << "NO" << endl;
        return 0;
    }

    //Se chegamos até aqui, tem que haver uma solução. Vamos alterar os pesos das arestas
    //do caminho mínimo de modo que a soma seja L. Depois, repetimos o processo (caso o
    //caminho tenha mudado), até que o caminho mínimo se "estabilize"
    while(1){
        //recuperar caminho mínimo alterando o primeiro peso
        ll valor_faltante = L - dist;
        int no = t;
        bool alterou = false;
        //alterarPeso(no, p[no], pesoAresta[make_pair(no, p[no])] + valor_faltante);
        //no = p[no];
        map<pair<int,int>, bool> caminhoMin;
        while(p[no] != -1){
            pair<int, int> ed = make_pair(no, p[no]);
            caminhoMin[ed] = true;
            caminhoMin[make_pair(p[no], no)] = true;
            if (ehVar.count(ed) && !alterou && !alterado.count(ed)){
                alterarPeso(no, p[no], pesoAresta[make_pair(no, p[no])] + valor_faltante);
                alterou = true;
            }
            no = p[no];
        }

        //alterar os outros pesos variáveis para infinito
        for(i = 0; i < (int)arestasVar.size(); i++){
            if (caminhoMin.count(arestasVar[i]))
                continue;
            alterarPeso(arestasVar[i], INFI);
        }
        //alterado.clear();
        dist = dijkstra(s, t, VARIAVEL, n);
        if (dist == L)
            break;
    }
    cout << "YES" << endl;
    for(i = 0; i < (int)arestasOrdem.size(); i++){
        cout << arestasOrdem[i].first << " " << arestasOrdem[i].second << " " << pesoAresta[arestasOrdem[i]] << endl;
    }
}