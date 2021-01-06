/*
Problema: Request for Proposal
Categorias:
	adhoc > sorting
Dificuldade: facil
Descricao:
Dica:
Autor: Rodrigo Rosetti
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct {
	string nome;
	int compliance;
	double preco;
} proposta;

bool comp(proposta a, proposta b) {
	return (a.compliance > b.compliance || (a.compliance == b.compliance && a.preco < b.preco));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, r, t = 1;
	while (cin >> n >> p >> ws && (n || p)) {
		vector<proposta> v;
		string lixo, nome;
		double preco;
		for (int i = 0; i < n; i++) getline(cin, lixo);
		while (p--) {
			getline(cin, nome);
			cin >> preco >> r >> ws;
			for (int i = 0; i < r; i++) getline(cin, lixo);
			proposta a;
			a.nome = nome, a.preco = preco, a.compliance = r;
			v.push_back(a);
		}
		if (t != 1) cout << endl; 
		cout << "RFP #" << t << endl;
		stable_sort(v.begin(), v.end(), comp);
		cout << v[0].nome << endl;
		t++;
	}
	return 0;
}