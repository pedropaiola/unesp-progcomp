/*
Problema: Consecutive Letters
Categorias:
	data structure > disjoint set
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 200001

using namespace std;

int p[MAXN];
int tam[MAXN];

void init(int n){
    for(int i = 0; i < n; i++){
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
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t, i, k, q, n;
    cin >> t;
    for(k = 1; k <= t; k++){
        string S;
        int op, x;
        vector<pair<int, char> > queries;
        vector<int> resp;

        cin >> S;
        n = S.size();
        init(n);

        cin >> q;
        for(i = 0; i < q; i++){
            cin >> op >> x;
            if (op == 2){
                queries.emplace_back(x, S[x]);
                S[x] = '#';
            }
            else
            {
                queries.emplace_back(x,'-');
            }
        }

        for(i = 0; i < n - 1; i++){
            if (S[i] == '#')
                continue;
            if (S[i] == S[i+1])
                merge(i, i+1);
        }
        for(i = q - 1; i >= 0; i--){
            x = queries[i].first;
            if (queries[i].second != '-')
            {
                S[x] = queries[i].second;
                if (x - 1 >= 0 && S[x] == S[x-1])
                    merge(x, x-1);
                if (x + 1 < n && S[x] == S[x+1])
                    merge(x, x+1);
            }
            else
            {
                resp.push_back(tam[find(x)]);                
            }
        }
        cout << "Case " << k << ":" << endl;
        for(i = resp.size() - 1; i >= 0; i--){
            cout << resp[i] << endl;
        }
    }
}