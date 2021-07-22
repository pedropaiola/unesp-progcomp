/*
Problema: DiceGames
Categorias:
	math > combinatorics
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 33

using namespace std;

class DiceGames{
    private:
        vector<int> sides;

        long dp[MAXN][MAXN];

        long solve(int i, int j){
            if (dp[i][j] != -1)
                return dp[i][j];
            if (i == 0)
                return dp[i][j] = 1;
            
            long resp = 0;
            for(int k = 1; k <= min(j, sides[i-1]); k++){
                resp += solve(i-1, k);
            }
            return dp[i][j] = resp;
        }
    public:
        long countFormations(vector<int> sides){
            int n = sides.size();
            sort(sides.begin(), sides.end());
            this->sides = sides;
            memset(dp, -1, sizeof(dp));
            long resp = 0;
            for(int j = 1; j <= sides[n-1]; j++)
                resp += solve(n-1, j);
            return resp;
        }
};
