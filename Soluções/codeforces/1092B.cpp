/*
Problema: Teams
Categorias:
	adhoc > sorting
Dificuldade: muito facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, total = 0, s, i;
    vector<int> skill;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> s;
        skill.push_back(s);
    }
    sort(skill.begin(), skill.end());
    for(i = 0; i < n; i += 2){
        total += skill[i+1] - skill[i];
    }
    cout << total << endl;
}