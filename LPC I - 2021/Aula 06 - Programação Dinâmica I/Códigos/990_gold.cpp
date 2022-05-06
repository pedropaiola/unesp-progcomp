/*
Problema: Diving for Gold
Categorias:
    dynamic programming > knapsack
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXD 1001
#define MAXT 31

using namespace std;

int dp[MAXT][MAXD];
int weight[MAXT];
int depth[MAXT];
int value[MAXT];
int escolhido[MAXT][MAXD];

int knapsack(int n, int w){
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    for(int j=0; j<=w; j++)
        dp[0][j] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(weight[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
            {
                int naoEscolher = dp[i-1][j];
                int escolher = dp[i-1][j-weight[i-1]] + value[i-1];
                if (naoEscolher > escolher){
                    dp[i][j] = naoEscolher;
                    escolhido[i-1][j] = 0;
                } else {
                    dp[i][j] = escolher;
                    escolhido[i-1][j] = 1;
                }
            }
        }
    }
    return dp[n][w];
}

vector<int> itensEscolhidos(int n, int w){
    vector<int> resp;
    for(int i = n-1; i >= 0; i--){
        if(escolhido[i][w])
        {            
            resp.push_back(i);
            w -= weight[i];
            if (w == 0)
                break;
        }
    }
    return resp;
}


int main(){
    int t, w, n, i;
    bool pula = false;
    while(cin >> t >> w){
        cin >> n;

        if(pula)
            cout << endl;
        pula = true;

        for(i = 0; i < n; i++)
        {
            cin >> depth[i] >> value[i];
            weight[i] = 3*w*depth[i];
        }
        cout << knapsack(n, t) << endl;
        vector<int> tesouros = itensEscolhidos(n, t);
        cout << tesouros.size() << endl;
        for(i = tesouros.size() - 1; i >= 0; i--){
            cout << depth[tesouros[i]] << " " << value[tesouros[i]] << endl;
        }
    }
}