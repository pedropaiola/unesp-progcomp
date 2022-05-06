/*
Problema: Cards
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
    int n, cont0 = 0, cont1 = 0, i;
    string s;
    cin >> n >> s;
    for(i = 0; i < n; i++){
        if (s[i] == 'z')
            cont0++;
        else if (s[i] == 'n')
            cont1++;
    }
    if (cont1 > 0)
        cout << 1;
    for(i = 1; i < cont1; i++)
        cout << " 1";
    if (cont0 > 0)
        cout << (cont1 == 0 ? "" : " ") << 0;
    for(i = 1; i < cont0; i++)
        cout << " 0";
    cout << endl;
}