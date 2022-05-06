/*
Problema: Maximum Increase
Categorias:
    gready
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, cur, resp, i;
    int a, b;

    cin >> n;
    resp = cur = 1;
    cin >> a;
    for(i = 1; i < n; i++){
        cin >> b;
        if (b > a){
            cur++;
            resp = max(resp, cur);
        } 
        else
            cur = 1;
        a = b;
    }
    cout << resp << endl;
}