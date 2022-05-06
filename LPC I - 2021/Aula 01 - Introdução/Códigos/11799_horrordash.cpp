/*
Problema: Horror Dash
Categorias:
	adhoc
Dificuldade: muito facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n, vel, velMax;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        velMax = 0;
        for(int j = 0; j < n; j++)
        {
            cin >> vel;
            if (vel > velMax)
                velMax = vel;
        }
        cout << "Case " << i << ": " << velMax << endl;
    }
}
