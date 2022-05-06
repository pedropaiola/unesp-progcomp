#include<bits/stdc++.h>
#define MAX_N 20002

using namespace std;

int pai[MAX_N];
int tam[MAX_N];

int amigos(int x){
    return x;
}

int inimigos(int x){
    return MAX_N/2 + x;
}

void init(){
    for(int i = 1; i <= MAX_N/2; i++){
        pai[i] = i;
        tam[i] = 1;
    }
    for(int i = MAX_N/2 + 1; i < MAX_N; i++){
        pai[i] = 0;
        tam[i] = 0;
    }
}

int find(int x){
    if (pai[x] == x || pai[x] == 0)
        return x;
    return pai[x] = find(pai[x]);
}

int same(int x, int y){
    return (find(x) == find(y));
}

void merge(int u, int v){
    int a = find(u);
    int b = find(v);
    if (tam[a] < tam[b])
        swap(a, b);
    pai[b] = a;
    tam[a] += tam[b]; 
}

int main(){
    int n, op, x, y;
    cin >> n;
    init();
    while(1)
    {
        cin >> op >> x >> y;
        x++; y++;
        if (!op)
            break;
        if (op == 1)
        {
            if (same(amigos(x), inimigos(y)))
                cout << "-1" << endl;
            else
            {
                merge(amigos(x), amigos(y));
                merge(inimigos(x), inimigos(y));
            }
        }
        else if (op == 2)
        {
            if (same(amigos(x), amigos(y)))
                cout << "-1" << endl;
            else
            {
                merge(amigos(x), inimigos(y));
                merge(inimigos(x), amigos(y));
            }
        }
        else if (op == 3)
        {
            cout << same(amigos(x), amigos(y)) << endl;
        }
        else
        {
            cout << same(amigos(x), inimigos(y)) << endl;
        }
    }
}