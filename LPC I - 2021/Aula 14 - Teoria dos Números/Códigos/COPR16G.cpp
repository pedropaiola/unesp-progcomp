/*
Problema: Get AC in one go
Categorias:
	math
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    long long int a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", __gcd(a,b)==1 ? a*b - a - b + 1 : -1);
    }
}
