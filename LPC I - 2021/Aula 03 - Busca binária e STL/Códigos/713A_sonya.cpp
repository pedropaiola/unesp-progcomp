/*
Problema: Sonya and Queries
Categorias:
    data structure > map
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/
#include <iostream>
#include <map>

using namespace std;

long long cod(long long num)
{
	long long x = 0, i = 1;
	while(num > 0)
	{
		x += (num % 2) * i;
		num /= 10;
		i *= 10;
	}
	return x;
}

int main()
{
	map<long long, long long> memo;
	long long a, x, t;
	char c;
	cin >> t;
	for(long long i = 0; i < t; i++)
	{
		cin >> c >> a;
		if (c == '+')
            memo[cod(a)]++;
		else if (c == '-')
			memo[cod(a)]--;
		else
			cout << memo[a] << endl;
	}
}