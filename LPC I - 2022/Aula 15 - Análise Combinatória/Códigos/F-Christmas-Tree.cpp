/*
Problema: ChristmasTree
Categorias:
	math > combinatorics
    dynamic programming
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define LEVELS 11
#define COLORS 51

using namespace std;

class ChristmasTree{
    private:
        long dp[LEVELS][COLORS][COLORS][COLORS];

        long fat(int x){
            long r = 1;
            for(int i = 1; i <= x; i++){
                r *= i;
            }
            return r;
        }
    public:
        ChristmasTree(){
            memset(dp, -1, sizeof(dp));
        }

        long decorationWays(int N, int red, int green, int blue){
            if (dp[N][red][green][blue] != -1)
                return dp[N][red][green][blue];
            
            if (red < 0 || green < 0 || blue < 0)
                return dp[N][red][green][blue] = 0;
            if (N == 1){
                return dp[N][red][green][blue] = (red > 0) + (green > 0) + (blue > 0);
            }

            long resp = decorationWays(N-1, red - N, green, blue) + 
                        decorationWays(N-1, red, green - N, blue) +
                        decorationWays(N-1, red, green, blue - N);

            if (N % 2 == 0){
                long qtdePermut = fat(N)/(fat(N/2)*fat(N/2));
                resp += qtdePermut*decorationWays(N-1, red - N/2, green - N/2, blue);
                resp += qtdePermut*decorationWays(N-1, red - N/2, green, blue - N/2);
                resp += qtdePermut*decorationWays(N-1, red, green - N/2, blue - N/2);
            }

            if (N % 3 == 0){
                resp += (fat(N)/(fat(N/3)*fat(N/3)*fat(N/3)))*decorationWays(N-1, red - N/3, green - N/3, blue - N/3);
            }
            
            return resp;
        }
};