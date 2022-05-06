/*
Problema: AND Grid
Categorias:
	ad-hoc
    greedy
Dificuldade: medio
Descricao:
Dica: Independente das intersecções de entrada, conseguimos gerar duas regiões
      disjuntas de forma que cada intersecção já esteja em uma das regiões, e
      com a distância de apenas uma posição da outra?
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 501

using namespace std;

int main()
{
    string red[MAXN], blue[MAXN], purple[MAXN];
    int H, W, i, j;

    cin >> H >> W;
    for(i = 0; i < H; i++){
        cin >> purple[i];
        red[i] = blue[i] = purple[i];
    }

    for(j = 0; j < W; j++)
        red[0][j] = blue[H-1][j] = '#';

    for(i = 1; i < H-1; i++)
    {
        for(j = 0; j < W; j++)
        {
            if (j % 2)
                red[i][j] = '#';
            else
                blue[i][j] = '#';
        }
    }

    for(i = 0; i < H; i++)
        cout << red[i] << endl;
    cout << endl;
    for(i = 0; i < H; i++)
        cout << blue[i] << endl;
}