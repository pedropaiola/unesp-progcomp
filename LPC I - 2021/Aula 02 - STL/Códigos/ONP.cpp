/*
Problema: Transform the Expression
Categorias:
	data structure > stack
Dificuldade: medio
Descricao: Determinar a forma RPN (Reverser Polish Notation) de uma expressão algébrica
Dica: o fato de não possuir expressões com mais de dois operandos sem parênteses ajuda muito mesmo!
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    
    cin >> n;
    while(n--)
    {
        cin >> s;
        stack<char> op;
        for(char c : s)
        {
            if (isalpha(c))
                cout << c;
            else if (c == ')')
            {
                cout << op.top();
                op.pop();
            }
            else if (c != '(')
                op.push(c);
        }
        cout << endl;
    }
}