/*
Problema: Making Jumps
Categorias:
    backtracking
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAX 30

using namespace std;

int n;
vector<pair<int, int>> tab;
map<pair<int, int>, int> m;
vector<pair<int, int>> movimentos = {{2, 1}, {1, 2}, {-1, 2},{-2, 1}, 
                                     {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

bool posicaoValida(int x, int y){
    return (x >= 0) && (x < n) && (y >= tab[x].first) && (y <= tab[x].second) && (!m.count({x, y}) || m[{x, y}] == 0);
}

int passeioCavalo(int x, int y){
    m[{x, y}] = 1;
    int casasAtingidas = 0;
    for(auto mov : movimentos){
        int x2 = x + mov.first;
        int y2 = y + mov.second;
        if (posicaoValida(x2, y2)){ //Verificando se é possível fazer este movimento
            casasAtingidas = max(casasAtingidas, passeioCavalo(x2, y2));
        }
    }
    m[{x, y}] = 0;
    return casasAtingidas + 1;
}

int main(){
    int i, j, casasPuladas, qtdeCasas, totalCasas, x, y;
    int caso = 1;
    while(true){
        cin >> n;
        if (n == 0)
            break;

        totalCasas = 0;
        x = 0;
        for(i = 0; i < n; i++){
            cin >> casasPuladas >> qtdeCasas;
            if (i == 0){
                y = casasPuladas;
            }
            tab.push_back({casasPuladas, casasPuladas + qtdeCasas - 1});
            totalCasas += qtdeCasas;
        }
        int resp = totalCasas - passeioCavalo(x,y);
        cout << "Case " << caso++ << ", " << resp <<
                (resp == 1 ? " square" : " squares")  << 
                " can not be reached." << endl;
        tab.clear();
        m.clear();
    }
}