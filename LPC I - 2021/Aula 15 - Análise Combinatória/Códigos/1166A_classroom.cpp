/*
Problema: Silent Classroom
Categorias:
	math > combinatorics
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i;
    int qtdeAlunos[256];
    string s;
    memset(qtdeAlunos, 0, sizeof(qtdeAlunos));

    cin >> n;
    for(i = 0; i < n; i++){
        cin >> s;
        qtdeAlunos[s[0]]++;
    }

    int x = 0;
    for(char c = 'a'; c <= 'z'; c++){
        if (!qtdeAlunos[c])
            continue;
        int q1 = qtdeAlunos[c] / 2;
        int q2 = q1 + qtdeAlunos[c] % 2;
        x += q1*(q1-1)/2 + q2*(q2-1)/2;
    }

    cout << x << endl;
}