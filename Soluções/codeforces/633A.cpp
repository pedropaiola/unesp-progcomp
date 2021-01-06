/*
Problema: Ebony and Ivory
Categorias:
	math > number theory > diophantine
Dificuldade: facil
Descricao: 
Dica: 
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int &x, int &y){
    if (b == 0){
            x = 1;
            y = 0;
            return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}

bool solve(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main(){
    int a, b, c, g, x0, y0, ini, fim, resto;
    cin >> a >> b >> c;
    if (solve(a, b, c, x0, y0, g)){
        ini = -x0*g/b; 
        resto = abs(x0*g % b);
        if (resto && -x0*g/(double)b > 0){
            ini++;
        }
        fim = y0*g/a;
        resto = abs(y0*g % a);
        if (resto && y0*g/(double)a < 0){
            fim--;
        }
        //cout << g << " " << x0 << " " << y0 << " " << ini << " " << fim << endl;
        if (fim - ini < 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;                      
    }
    else
    {
        cout << "No" << endl;
    }
    
}