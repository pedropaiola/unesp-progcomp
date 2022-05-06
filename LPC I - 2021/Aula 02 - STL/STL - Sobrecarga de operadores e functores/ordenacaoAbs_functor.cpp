//ORDENAÇÃO CONSIDERANDO VALOR ABSOLUTO, USANDO FUNCTOR
#include<bits/stdc++.h>

using namespace std;

//Um functor é, a príncipio, uma simples função, no caso, uma função que compara dois números.
//Essa função passa a ser considerada um functor quando ela é passada por parâmetro (como se fosse um objeto)
//em uma determinada função, no nosso exemplo ela será usada no sort()
bool compAbsoluto(const int &a, const int &b) 
{
	//O original seria algo como "return a < b";
	return abs(a) < abs(b); //comparando valores absolutos
}

int main()
{
	vector<int> vet = {-4, 2, -1, 4, 9, -2, -10, 20};
	sort(vet.begin(), vet.end(), compAbsoluto); //passando a função compAbsoluto por parâmetro
	for(int i = 0; i < vet.size(); i++)
		cout << vet[i] << " ";
}
