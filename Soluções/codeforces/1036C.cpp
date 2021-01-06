/*
Problema: Classy Numbers
Categorias:
	dynamic programming > digit
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>
#define ll long long int

using namespace std;

//dp[indíce do algarismo][qtde de não zeros no número][limitado ou não] 
ll dp[20][20][2];

void initDP()
{
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            dp[i][j][0] = dp[i][j][1] = -1;
}


ll solve(int idx, int qtdeNZ, int t, vector<int> &v){
    if (idx == -1)
        return 0;
    if (dp[idx][qtdeNZ][t] != -1)
        return dp[idx][qtdeNZ][t];

    //Se já temos mais que 3 não-zeros, podemos parar a busca nesse ramo
    if (qtdeNZ > 3)
        return dp[idx][qtdeNZ][t] = 0;

    int limit = (t ? v[idx] : 9); 
    ll ans = 0;

    if (idx == 0){
        //Chegamos no último dígito
        if (qtdeNZ < 3) //Se temos menos que 3 não-zeros, podemos colocar quando número de 0 a limit
            ans = limit + (qtdeNZ != 0);    //se SÓ temos zeros, então não podemos colocar o próprio 0 (000...000 não conta como classy number)
        else  //Se temos exatamente 3 não-zeros, então só temos uma possibilidade para o último número, que é colocar 0
            ans = 1;     
    }
    else
    {
        for(int i = 0; i < limit; i++){ //Verificando todas as possibilidades, selecionado dígitos entre 0 e limit
            ans += solve(idx-1, qtdeNZ + (i != 0), 0, v);   //Se o dígito for diferente de 0, então incrementamos qtdeNZ
        }
        ans += solve(idx-1, qtdeNZ + (limit != 0), t, v); //Caso aplicado ao próprio limit, em que temos que limitar o próximo digito
    }                              
    dp[idx][qtdeNZ][t] = ans;
    return ans;
}

vector<int> num2vector(ll num)
{
	vector<int> v;
	while(num > 0)
	{
		v.push_back(num % 10);
		num /= 10;
	}
	return v;
}

int main(){
    int t;
    ll l, r;
    vector<int> vL, vR;
    ll respL, respR;

    cin >> t;
    while(t--){
        cin >> l >> r;
        vL = num2vector(l-1);
        vR = num2vector(r);
        initDP();
        respL = solve(vL.size()-1, 0, 1, vL);
        //cout << respL << endl;
        initDP();
        respR = solve(vR.size()-1, 0, 1, vR);
        //cout << respR << endl;
        cout << respR - respL << endl;
    }
}