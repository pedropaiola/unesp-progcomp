/*
Problema: Monitor
Categorias:
	math
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int mdc = gcd(x,y);
    x /= mdc;
    y /= mdc;
    //Agora temos x/y na forma mais simplificada possível, e então queremos
    //descobrir a razão a'/b' que seja equivalente de x/y de forma a maximizar a' * b. 
    //Ou seja, o maior m tal que x*m = a' e y*m = b'
    //Mas a' <= a e b' <= b, então vamos descobrir o maior m de forma que 
    //esses valores não sejam ultrapassados.
    //Se x * m = a' <= a
    //  Então x * m <= a
    //             m <= a/x
    //De forma análoga, m <= b/y
    //Logo, o valor que o queremos é o menor entre a/x e b/y, para respeitar ambas as restrições
    int m = min(a/x, b/y);
    cout << x*m << " " << y*m << endl; 
}