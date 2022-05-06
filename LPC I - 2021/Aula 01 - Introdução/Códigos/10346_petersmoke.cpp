#include<iostream>

using namespace std;

int main()
{
	int n, k, soma, bitucas;
	while(cin >> n >> k)
	{
		soma = n;
		bitucas = n;
		while(bitucas >= k)
		{
			n = bitucas/k;
			soma += n;
			bitucas = bitucas % k + n;
		}
		cout << soma << endl;
	}
}