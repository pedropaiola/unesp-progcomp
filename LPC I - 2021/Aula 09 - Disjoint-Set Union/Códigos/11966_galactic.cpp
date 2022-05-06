/*
Problema: Galactic Bonding
Categorias:
    data structure > disjoint set
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 1000

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

bool same(int a, int b){
    return find(a) == find(b);
}

double dist2(double x1, double y1, double x2, double y2){
    return (y2-y1)*(y2-y1) + (x2 - x1)*(x2 - x1);
}

int main(){
    int t, n, k, i, j, ans;
    double d, x, y;
    vector<pair<double, double> > pontos;
    cin >> t;
    for(k = 1; k <= t; k++){
        cin >> n >> d;
        if (n == 0)
        {
            cout << "Case " << k << ": 0" << endl;
            continue;
        }
        init(n);
        d *= d; //Mais fácil trabalhar com d^2
        pontos.clear();
        ans = n;
        //Lendo pontos e formando os conjuntos de constelações
        for(i = 0; i < n; i++){
            cin >> x >> y;
            for(j = 0; j < pontos.size(); j++){
                if ((dist2(x, y, pontos[j].first, pontos[j].second) <= d) && !same(i,j)){
                    merge(i, j);    //se os pontos obedecem a restrição, juntamos na mesma constelação
                    ans--;
                }
            }
            pontos.push_back({x,y});
        }
        cout << "Case " << k << ": " << ans << endl;
    }
}