#include<bits/stdc++.h>

using namespace std;

int soma_dig(int i){
	int soma = 0;
	while(i > 0){
		soma += i % 10;
		i /= 10;
	}
	return soma;
}

int main(){
	int n, m, s;
	int maior = -1;
	
	cin >> n >> m >> s;
	for(int i = n; i <= m; i++){
		if (soma_dig(i) == s)
			maior = i;
	}
	cout << maior << "\n";
}