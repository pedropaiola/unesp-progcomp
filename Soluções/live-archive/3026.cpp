/*
Problema: Period
Categorias:
	strings > kmp
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define MAXN 1000001

using namespace std;

int a[MAXN], m;
string P;

void calculatePrefix(){
    int i = 0, j = -1;
    a[0] = -1;
    while(i < m){
        while(j >= 0 && P[i] != P[j]) 
            j = a[j];
        i++; j++;
        a[i] = j;
    }
}

int main(){
    int caso = 1;
    while(cin >> m){
        if (m == 0)
            break;
        cin >> P;
        calculatePrefix();
        cout << "Test case #" << caso++ << endl;
        for(int i = 1; i < m; i++){
            if (a[i+1] == 0) continue;
            int tamPref = i + 1;
            int tamPeriod = tamPref - a[i+1];
            if ((tamPref - 2*tamPeriod) % tamPeriod == 0){
                cout << tamPref << " " << tamPref/tamPeriod << endl;
            }
        }
        cout << endl;
    }
}