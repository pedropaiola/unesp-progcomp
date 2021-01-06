/*
Problema: Crazy Town
Categorias:
	math > geometry
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include<iostream>

using namespace std;

int main()
{
	long long casax, casay, univx, univy;
	long long a, b, c, s1, s2;
	long long n, cont = 0;
	
	cin >> casax >> casay;
	cin >> univx >> univy;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		s1 = a*casax + b*casay + c;
		s2 = a*univx + b*univy + c;
		if (s1 > 0 && s2 < 0 || s2 > 0 && s1 < 0)
			cont++;
	}
	cout << cont << endl;
}
