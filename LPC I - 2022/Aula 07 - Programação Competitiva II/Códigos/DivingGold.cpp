//Diving for Gold - https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=931

#include <bits/stdc++.h>
using namespace std;
#define no_tle_pls               \
    ios::sync_with_stdio(false); \
    cin.tie(0)
typedef long long int ll;

// Variáveis Globais:
ll t, w, n;

void knapsack(vector<pair<int, int>> &th, vector<vector<ll>> &dp){
    for (int i = 1; i <= n; i++)
        {
            ll d, v;
            tie(d, v) = th[i];
            ll td = d * w + (2 * w) * d;
            for (int j = 1; j <= t; j++)
            {
                if (j < td)
                {
                    //Salva a situação anterior (antes de adicionar o objeto i atual)
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    /* Salva o máximo entre a situação anterior (antes de adicionar o objeto i atual) 
                       e a possibilidade de adicionar o objeto i */
                    dp[i][j] = max(dp[i - 1][j - td] + v, dp[i - 1][j]);
                }
            }
        }
     cout << dp[n][t] << "\n";
}


void caminhando_na_dp(vector<pair<int, int>> &th, vector<vector<ll>> &dp)
{
    ll i = n, j = t;
    vector<pair<int, int>> ans;
    ll ant = dp[n][t];
    bool f = 0;
    for (; i > 0; i--)
    {
        ll d, v;
        tie(d, v) = th[i];
        ll td = d * w + (2 * w) * d;

        for (int k = j; k >= 1; k--)
        {
            /* Se:
               voltando na posicão em que foi adicionado o objeto i, 
               a dp for igual a dp da posicão atual, 
               quer dizer que esse valor foi salvo (máximo na situação) na dp,
               logo esse objeto foi adicionado. 
               
               Senão:
                esse objeto não foi adicionado, pois não era o melhor (maximo) na situação 
                e devemos continuar verificando os anteriores considerando a mesma posição de tempo

               */
            
            if (td <= k && dp[i][k] == dp[i - 1][k - td] + v)
            {
                ans.push_back(th[i]);
                j = k - td;
                break;
            }
            else
            {
                j = k;
                break;
            }
        }
    }

    cout << ans.size() << "\n";

    for (i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

}

int main()
{
    no_tle_pls;

    bool pular_linha = 0;
    while (cin >> t >> w)
    {
        //Sempre que aparecer um novo caso de teste ele pula linha se for true
        if (pular_linha)
            cout << "\n";
        pular_linha = true;


        cin >> n;
        //Declarando o vetor de duas dimensões da DP
        vector<vector<ll>> dp(n + 1, vector<ll>(t + 1));
        //Salvando os dados passados pelo problema
        vector<pair<int, int>> th;
        //Dando push_back no vetor para inicializar a partir do indice 1
        th.push_back({0, 0}); 

        for (int i = 0; i < n; i++)
        {
            ll d, v;
            cin >> d >> v;
            th.push_back({d, v});
        }

        //Chamando a DP de Knapsack
        knapsack(th,dp);
        //Fazendo o caminho contrário e pegando os valores modificados
        caminhando_na_dp(th,dp);
       
    }
    return 0;
}
