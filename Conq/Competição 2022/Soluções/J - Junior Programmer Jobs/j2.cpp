/*
  Problema J - Junior Programmer Jobs
  Basta utilizar um set para manter o conjunto ordenado.
*/
#include <bits/stdc++.h>

using namespace std;

//Classe para representar uma pessoa
struct Pessoa {
    //Atributos
    string nome;
    float nota;

    //Construtor
    Pessoa(string nome, float nota) {
        this->nome = nome;
        this->nota = nota;
    }

    //Operador para comparar duas pessoas (e assim manter o set ordenado)
    bool operator<(const Pessoa &p) const {
        if (nota == p.nota) {
            return nome < p.nome;
        }
        return nota > p.nota;
    }
};

int main(){
    multiset<Pessoa> conjunto;
    char op;
    int qtde;
    string nome, sobrenome;
    float nota;
    
    cout << fixed << setprecision(1);
    while(cin >> op){
        if (op == 'I')
        {
            cin >> nome >> sobrenome >> nota;
            Pessoa aux(nome + " " + sobrenome, nota);
            conjunto.insert(aux);
        }
        else
        {
            cin >> qtde;
            for(auto p : conjunto){
                cout << p.nota << " " << p.nome << "\n";
                qtde--;
                if (qtde == 0)
                    break;
            }
            cout << "----------\n";
        }
    }
}