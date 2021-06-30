/*
Problema: Roads of NITT
Categorias:
	data structure > disjoint set
Dificuldade: dificil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 20001

using namespace std;

int p[MAXN];
int tam[MAXN];

void init(int n){
    for(int i = 1; i <= n; i++){
        p[i] = i;
        tam[i] = 1; //A principio, cada conjunto contém apenas ele mesmo
    }
}

int find(int x){
    if (p[x] == x) 
        return x;
    return p[x] = find(p[x]); //Aplicando path compression
}

void merge(int a, int b){
    int setA = find(a);
    int setB = find(b);
    if (setA == setB) //Ja sao o mesmo conjunto
        return;
    if (tam[setA] > tam[setB])
        swap(setA, setB);   //queremos que setU seja o menor conjunto
    p[setA] = setB;         //liga a em b
    tam[setB] += tam[setA]; //atualiza o tamanho de b
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q, i, x, y;
        char c;
        vector<pair<int, int>> road;
        vector<bool> check;
        vector<int> op;
        vector<int> resp;

        cin >> n;
        for(i = 1; i < n; i++){
            cin >> x >> y;
            road.push_back({x, y});
            check.push_back(true);
        }
        cin >> q;
        for(i = 0; i < q; i++){
            cin >> c;
            if (c == 'R'){
                cin >> x;
                op.push_back(x);
                check[x-1] = false;
            }
            else
                op.push_back(0);
        }

        init(n);
        int total_pairs = n*(n-1)/2;
        int conn = 0;

        for(i = 0; i < n-1; i++){
            if (check[i]){
                x = road[i].first;
                y = road[i].second;
                conn += tam[find(x)]*tam[find(y)];
                merge(x, y);
            }
        }

        for(i = q-1; i >= 0; i--){
            if (op[i] == 0)
                resp.push_back(total_pairs - conn);
            else
            {
                x = road[op[i] - 1].first;
                y = road[op[i] - 1].second;
                conn += tam[find(x)]*tam[find(y)];
                merge(x, y);
            }
        }
        for(i = resp.size() - 1; i >= 0; i--){
            cout << resp[i] << endl;
        }
        
        cout << endl;
    }
}