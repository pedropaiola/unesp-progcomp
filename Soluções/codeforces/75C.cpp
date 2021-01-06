/*
Problema: Modified GCD
Categorias:
	math > number theory
    binary search
Dificuldade: medio
Descricao: 
Dica: 
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b, n, low, high, mdc, i;
    vector<int> divisores;

    cin >> a >> b;

    mdc = __gcd(a, b);
    for(i = 1; i * i <= mdc; i++){
        if (mdc % i == 0){
            divisores.push_back(i);
            divisores.push_back(mdc/i);
        }
    }
    sort(divisores.begin(), divisores.end());

    cin >> n;
    while(n--){
        cin >> low >> high;
        i = upper_bound(divisores.begin(), divisores.end(), high) - divisores.begin();
        if (divisores[i-1] >= low)
            cout << divisores[i-1] << endl;
        else
            cout << -1 << endl;
    }
}