/*
Problema: A problem of Backtracking
Categorias:
    backtracking
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll a[10], k;

bool backtracking(vector<int> &sol, bool utilizado[10], ll soma){
    if (soma > k)
        return false;
    
    if (sol.size() == 10)
        return true;
    
    for(int i = 0; i < 10; i++){
        if (!utilizado[i]){
            utilizado[i] = true;
            sol.push_back(i);
            if (backtracking(sol, utilizado, soma + a[sol.size()-1] * i))
                return true;
            sol.pop_back();
            utilizado[i] = false;
        }
    }

    return false;
}


int main(){
    int t, i;
    cin >> t;
    while(t--){
        for(i = 0; i < 10; i++)
            cin >> a[i];
        cin >> k;
        bool utilizado[10];
        vector<int> sol;

        memset(utilizado, 0, sizeof(utilizado));
        if (backtracking(sol, utilizado, 0)){
            for(i = 0; i < 9; i++)
                cout << sol[i] << " ";
            cout << sol[i] << endl;
        }
        else
            cout << -1 << endl;
    }
}