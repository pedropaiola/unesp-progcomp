/*
Problema: And Reachability
Categorias:
	dynamic programming > bitmask
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 300000
#define MAXB 19 //ceil(log2(MAXN))

using namespace std;

int n;
int a[MAXN+1];
int dp[MAXN+1][MAXB];
int prox[MAXN+1][MAXB];

void preprocess(){
    //Primeiro, vemos para cada número a[i], quem podemos alcançar por cada bit ligado b de a[i]
    for(int b = 0; b < MAXB; b++){
        int proxAux = n;   //Primeiro j > i tal que o bit b está ligado (em ambos)
        for(int i = n-1; i >= 0; i--){
            if ((a[i] & (1 << b)) == 0){  //Se o bit b não está ligado
                prox[i][b] = n;
                continue;
            }
            prox[i][b] = (proxAux == n) ? i : proxAux; //Se está ligado, então eu posso alcançar lastAux através dele
            proxAux = i;
        }
    }
    //Por fim, para cada (i,k) descobrimos o menor x tal que a[x] contém o bit k e é alcançável por i. Em outras
    //palavras, queremos saber se somos capazes de chegar em algum a[x] com o bit k ligado (independente dele estar
    //ligado em a[i] ou não, pois podemos vir indiretamente através de um bit j)
    for(int k = 0; k < MAXB; k++){
        dp[n][k] = n;    //Acho que é desnecessário, mas por via das dúvidas...
        dp[n-1][k] = prox[n-1][k];
        for(int i = n-2; i >= 0; i--){
            dp[i][k] = n;
            for(int j = 0; j < MAXB; j++){
                if (a[i] & (1 << j)){
                    if (a[prox[i][j]] & (1 << k))
                        dp[i][k] = min(dp[i][k], prox[i][j]);
                    else
                        dp[i][k] = min(dp[i][k], dp[prox[i][j]][k]);
                }
            }
            if (dp[i][k] == n)
                dp[i][k] = prox[i][k];
        }    
    } 
}

int main(){
    int q, x, y;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = 0;
    preprocess();
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        x--; y--;
        bool alcanca = false;
        for(int j = 0; j < MAXB; j++){
            alcanca |= (a[y] & (1 << j)) && dp[x][j] <= y;
        }
        cout << (alcanca ? "Shi" : "Fou") << endl;
    }
}