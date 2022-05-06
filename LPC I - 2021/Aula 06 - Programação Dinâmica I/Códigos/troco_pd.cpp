#include<bits/stdc++.h>

using namespace std;

vector<int> moedas = {50, 25, 10, 5, 1};
map<int, int> memo;

int troco(int x){ 
    //Caso base
    if (x == 0){
        return 0;
    }

    //Subproblema já solucionado
    if (memo.count(x))
        return memo[x];

    //Ainda não chegamos na solução, então tentamos adicionar mais uma moeda
    memo[x] = INT_MAX;
    for(int m : moedas){
        if (m > x)
            continue;
        memo[x] = min(memo[x], 1 + troco(x-m));
    }
    return memo[x];
}

int main(){
    int x;
    cin >> x;
    cout << "Qtde de moedas usadas: " << troco(x) << endl;
}