#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <utility>

using namespace std;

struct Pessoa {
  string nome;
  float nota;

  Pessoa(string nome, float nota) {
    this->nome = nome;
    this->nota = nota;
  }

  bool operator<(const Pessoa &p) const {
    if (nota == p.nota) {
      return nome < p.nome;
    }
    return nota > p.nota;
  }
};

multiset<Pessoa> conjunto;

void leRestoLinha(string &nome, float &nota) {
  string primeiroNome, sobrenome;
  cin >> primeiroNome >> sobrenome >> nota;
  nome = primeiroNome + " " + sobrenome;
}

void leRestoLinha(int &n) { 
  cin >> n; 
}

void insere(string &nome, float &nota) { conjunto.insert(Pessoa(nome, nota)); }

void consulta(int n) {
  auto ite = conjunto.begin();
  for (int i = 0; i < n && ite != conjunto.end(); i++, ite++) {
    printf("%.1f %s\n", ite->nota, ite->nome.c_str());
  }
  printf("----------\n");
}

bool processsaLinha() {
  char op;

  if (!(cin >> op)) {
    return false;
  }
  switch (op) {
  case 'I': {
    string nome;
    float nota;
    leRestoLinha(nome, nota);
    // cout << op << nome << nota << endl;
    insere(nome, nota);
  } break;
  case 'C': {
    int n;
    leRestoLinha(n);
    // cout << op << n << endl;
    consulta(n);
  } break;
  default:
    break;
  }
  return true;
}

int main() {
  while (processsaLinha())
    ;
  return 0;
}