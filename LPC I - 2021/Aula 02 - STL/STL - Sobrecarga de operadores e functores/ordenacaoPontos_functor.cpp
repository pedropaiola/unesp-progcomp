//ORDENAÇÃO DE PONTOS, USANDO FUNCTOR
//a ideia aqui vai ser ordenar os pontos (pair<int, int>) de um vetor, considerando sua distância
//a um ponto pivô. Ou seja, ordenaremos os pontos por ordem crescente de distância a esse ponto pivô
#include<bits/stdc++.h>

using namespace std;

pair<int, int> pivo(4, 4);

bool comp(const pair<int, int> &a, const pair<int, int> &b) 
{
	int dA = (a.first - pivo.first)*(a.first - pivo.first) + (a.second - pivo.second)*(a.second - pivo.second);
	int dB = (b.first - pivo.first)*(b.first - pivo.first) + (b.second - pivo.second)*(b.second - pivo.second);
	return dA < dB;
}

int main()
{
	vector<pair<int, int>> vet = {{0,0}, {1,2}, {5,4}, {4,4}, {3,3}, {-1,2}, {4,5}};
	sort(vet.begin(), vet.end(), comp); //passando a função comp por parâmetro
	for(int i = 0; i < vet.size(); i++)
		cout << "(" << vet[i].first << "," << vet[i].second << ") ";
}
