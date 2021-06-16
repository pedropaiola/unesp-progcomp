/*
Problema: Snakes and transition from Capitalism to Socialism
Categorias:
    graphs
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXV 500

using namespace std;

int a[MAXV][MAXV];
int d[MAXV][MAXV];
int n, m;
vector<pair<int,int>> mov = {{-1, -1}, {-1, 0}, {-1, 1},
                             { 0, -1},          { 0, 1},
                             { 1, -1}, { 1, 0}, { 1, 1}};

bool posValida(int i, int j){
    return (i >= 0) && (i < n) && (j >= 0) && (j < m);
}

int main()
{
    int t;
    int i, j, aMax;
    int x, y;
    int dMax;
    queue<pair<int, int>> Q;
    
    cin >> t;
    while(t--)
    {
        aMax = dMax = 0;
        cin >> n >> m;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] > aMax)
                    aMax = a[i][j];
                d[i][j] = -1;
            }
        }
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if (a[i][j] == aMax)
                {
                    d[i][j] = 0;
                    Q.push({i, j});
                }
            }
        }
        
        while(!Q.empty()){
            i = Q.front().first;
            j = Q.front().second;
            Q.pop();
            
            for(auto p : mov){
                x = i + p.first;
                y = j + p.second;
                if (posValida(x, y) && d[x][y] == -1){
                    dMax = d[x][y] = d[i][j] + 1;
                    Q.push({x, y});
                }
            }
        }

        cout << dMax << endl;
    }
}