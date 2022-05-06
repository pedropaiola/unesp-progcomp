/*
Problema: Dragon of Loowater
Categorias:
    greedy
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, i, j, aux;
    while(true){
        cin >> n >> m;
        if (n == 0)
            break;
        
        vector<int> dragons, knights;
        int custo = 0;

        for(i = 0; i < n; i++){
            cin >> aux;
            dragons.push_back(aux);
        }

        for(i = 0; i < m; i++){
            cin >> aux;
            knights.push_back(aux);
        }

        sort(dragons.begin(), dragons.end());
        sort(knights.begin(), knights.end());

        j = 0;
        for(i = 0; i < n; i++){
            while(j < m && knights[j] < dragons[i])
                j++;
            if (j == m)
                break;
            custo += knights[j++];
        }
        if (i < n)
            cout << "Loowater is doomed!" << endl;
        else
            cout << custo << endl;
    }
}