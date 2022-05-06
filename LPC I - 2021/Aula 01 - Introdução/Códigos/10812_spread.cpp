/*
Problema: Beat the Spread!
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
    int t;
    int s, d, x, y;
    cin >> t;
    while(t--){
        cin >> s >> d;
        if ((s - d) >= 0 && ((s + d) % 2 == 0)) {
            x = (s + d) / 2;
            y = (s - d) / 2;
            cout << x << " " << y << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
        
    }
}