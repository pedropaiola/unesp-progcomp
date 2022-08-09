#include<bits/stdc++.h>

using namespace std;

int soma_dig(int i){
    int soma = i % 10;
    while(i > 1){
        i /= 10;
        soma += i % 10;
    }
    return soma;
}

int main(){
    int n, m, s;
    int maior = -1;
    int menor = -1;

    cin >> s >> n >> m;
    for(int i = n; i <= m; i++)
        if (soma_dig(i) == s){
            maior = i;
            if (menor == -1)
                menor = i;
        }
    cout << menor << "\n" << maior << "\n";
}