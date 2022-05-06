#include<bits/stdc++.h>
#define MAX 20

using namespace std;

int m[MAX][MAX], n;
vector<pair<int, int>> movimentos = {{2, 1}, {1, 2}, {-1, 2},
                                     {-2, 1}, {-2, -1}, {-1, -2},
                                     {1, -2}, {2, -1}};

void init(int x, int y){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            m[i][j] = 0;
    m[x][y] = 1;
}

bool posicaoValida(int x, int y){
    return (x >= 0) && (x < n) && (y >= 0) && (y < n) && !m[x][y];
}

int passeioCavalo(int x, int y){
    if (m[x][y] == n * n)
        return 1;   //Problema solucionado
    
    //Incrementando solução
    for(auto mov : movimentos){
        int x2 = x + mov.first;
        int y2 = y + mov.second;
        if (posicaoValida(x2, y2)){ //Verificando se é possível fazer este movimento
            m[x2][y2] = m[x][y] + 1;
            if (passeioCavalo(x2, y2))
                return 1;
            m[x2][y2] = 0;
        }
    }

    return 0; //Nenhuma solução encontrada neste ramo
}

void imprimirPasseio(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
   int x, y;
   cin >> n >> x >> y;
   init(x, y);
   if (passeioCavalo(x, y)){
       imprimirPasseio();
   } else {
       cout << "Solucao nao encontrada!" << endl;
   }
}