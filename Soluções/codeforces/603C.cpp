/*
Problema: Liege of Legendre
Categorias:
	math > game theory
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 100000

using namespace std;

int n, k;

int g(int a){
    if (a <= 1)
        return a;
    if (k % 2 == 0)
    {
        if (a == 2)
            return 2;
        return !(a % 2);
    }
    if (a == 2)
        return 0;
    if (a == 3)
        return 1;
    if (a == 4)
        return 2;

    if (a % 2)
        return 0;

    if (g(a/2) == 1)
        return 2;
    return 1;
}


int main(){
    cin >> n >> k;
    int a, resp = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        resp ^= g(a);
    }
    if (resp)
        cout << "Kevin" << endl;
    else
        cout << "Nicky" << endl;
}