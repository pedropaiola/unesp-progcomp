/*
Problema: The dominoes solitaire
Categorias:
    backtracking
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> pecas;
vector<bool> utilizada;
int ini, fim;

bool backtracking(int k, int ultimaPeca){
    if (k == n)
        return (ultimaPeca == fim);

    for(int i = 0; i < m; i++){
        if (!utilizada[i]){
            if (pecas[i].first == ultimaPeca){
                utilizada[i] = true;
                if (backtracking(k+1, pecas[i].second))
                    return true;
                utilizada[i] = false;
            } else if (pecas[i].second == ultimaPeca){
                utilizada[i] = true;
                if (backtracking(k+1, pecas[i].first))
                    return true;
                utilizada[i] = false;
            }
        }
    }
    return false;
}


int main(){
    int x, y;
    while(true){
        cin >> n;
        if (!n)
            break;
        cin >> m;

        cin >> x >> ini;
        cin >> fim >> y;

        pecas.clear();
        utilizada.clear();
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            pecas.push_back({x, y});
            utilizada.push_back(false);
        }
        if (backtracking(0, ini))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}