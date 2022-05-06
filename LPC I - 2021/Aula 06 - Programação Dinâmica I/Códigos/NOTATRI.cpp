/*
Problema: Not a Triangle
Categorias:
    binary search
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x;
    
    while(cin >> n){
        if(n == 0)
            break;

        int cnt = 0;
        vector<int> v;
        
        for(int i = 0; i < n; i++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int ind = upper_bound(v.begin(), v.end(), v[i] + v[j]) - v.begin();
                cnt += n - ind;
            }
        }
        cout << cnt << endl;
    }
}