/*
Problema: Lineup
Categorias:
	dynamic programming > bitmask
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

const int maxb = 1 << 11;
int strength[11][11];
int dp[maxb]; 


int count_set_bits(int mask){
    int cnt = 0;
    while(mask > 0){
        cnt += mask & 1;
        mask >>= 1;
    }
    return cnt;
}

//Problema da alocação de tarefas (porém, queremos maximizar o ganho)
int melhorFormacao(){
    for(int mask = 0; mask < maxb; mask++)
        dp[mask] = -INT_MAX;
    dp[0] = 0;
    for(int mask = 0; mask < maxb; mask++){
        int x = count_set_bits(mask);
        for(int j = 0; j < 11; j++){
            //OBS: se strength[x][j] == 0 a solução NÃO é válida, msm q no final a solução tivesse um ganho maior
            if ((mask & (1 << j)) || !strength[x][j]) 
                continue;

            dp[mask | (1 << j)] = max(dp[mask | (1 << j)], dp[mask] + strength[x][j]);
        }
    }
    return dp[maxb - 1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 11; i++)
            for(int j = 0; j < 11; j++)
                cin >> strength[i][j];
        cout << melhorFormacao() << endl;
    }
}