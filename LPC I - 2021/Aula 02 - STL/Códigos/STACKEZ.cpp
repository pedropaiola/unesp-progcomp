/*
Problema: Easy Stack
Categorias:
	data structure > stack
Dificuldade: muito facil
Descricao: 
Dica: fast-io (se utilizar cin e cout, não utilize endl, só \n)
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, op, num;
    stack<int> p;

    cin >> t;
    while(t--)
    {
        cin >> op;
        switch (op)
        {
            case 1:
                cin >> num;
                p.push(num);
                break;
            case 2:
                if (!p.empty())
                    p.pop();
                break;
            case 3:
                if (p.empty())
                    cout << "Empty!\n";
                else
                    cout << p.top() << "\n";
        
        }
    }
}