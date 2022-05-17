//============================================================================
// Name        : m.cpp
// Author      : Comini/Giulia/Paiola
// Version     :
// Copyright   : ICPC - Regional 2019 - Problema M - Maratona Brasileira de Comedores de Pipocas
// Description : Busca binária em relação ao tamanho máximo de cada "partição". Tentando um tamanho máximo
// 				 MED, cria-se uma partição até atingir o maior tamanho possível menor que MED, em seguida 
//				 passando para a próxima partição. Se não conseguirmos criar C partições dessa forma, aumentamos
//				 MED e tentamos novamente, se for possível, diminuimos MED para ver se é possível fazer com um tamanho menor.
//============================================================================
#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

int n, c;
int v[MAXN];

int solve(int ini, int fim){
	int med = (ini + fim)/2;
	int i, j, soma;
	bool deu;
	int melhor = 0;
	while(ini <= fim){
		j = 1;
		soma = 0;
		deu = true;
		for(i = 0; i < n; i++){
			soma += v[i];
			if (soma > med)
			{
				soma = 0;
				j++;
				i--;
				if (j > c){
					deu = false;
					break;
				}
			}
		}
		if (!deu){
			ini = med + 1;
			//cout << "!" << med << endl;
		} else {
			fim = med - 1;
			melhor = med;
			//cout << melhor << endl;
		}
		med = (ini + fim)/2;
	}
	return melhor;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, resp;
	int v_acc = 0, maior = 0;
	cin >> n >> c >> t;
	
	v_acc = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		v_acc += v[i];
		maior = max(maior, v[i]);
	}
		
	resp = solve(maior,v_acc);
	
	if (resp % t)
		resp = (resp/t) + 1;
	else
		resp /= t;
		
	cout << resp << endl;	
}
