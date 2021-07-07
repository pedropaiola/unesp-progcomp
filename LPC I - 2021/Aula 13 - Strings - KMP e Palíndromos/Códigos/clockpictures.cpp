/*
Problema: Clock Pictures
Categorias:
    strings > kmp
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A, B;

int a[400000], n1, m;
vector<int> A2, B2;

void calculatePrefix() {
	int i = 0, j = -1;
	a[0] = -1;
	while(i < m){
		while (j >= 0 && B2[i] != B2[j])
			j = a[j];
		i++; j++;
		a[i] = j;
	}
}

int KMP(){
	int i = 0, j = 0;
	calculatePrefix();
	while(i < n1){
		while(j >= 0 && A2[i] != B2[j])
			j = a[j];
		j++; i++;
		if(j == m)
			return i - m;
	}
	return -1;
}

int possivel(int n)
{
	int i, j, k;
	bool ok;
	
	n1 = 2*n;
	m = n;	
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for(i = 0; i < n - 1; i++)
		A2.push_back(A[i+1] - A[i]);
	A2.push_back(360000 - A[n-1] + A[0]);
	for(i = 0; i < n; i++)
		A2.push_back(A2[i]);
	for(i = 0; i < n - 1; i++)
		B2.push_back(B[i+1] - B[i]);
	B2.push_back(360000 - B[n-1] + B[0]);	
	if(KMP() == -1)
		return false;
	return true;
}

int main()
{
	int i, n, x;
	
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> x;
		A.push_back(x);
	}
	for(i = 0; i < n; i++)
	{
		cin >> x;
		B.push_back(x);
	}	
	
	if(possivel(n))
		cout << "possible" << endl;
	else
		cout << "impossible" << endl;
}