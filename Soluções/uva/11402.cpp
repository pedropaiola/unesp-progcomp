/*
Problema: Ahoy, Pirates!
Categorias:
	data structure > segment tree > lazy propagation
Dificuldade: medio
Descricao:
Dica:
Autor: Paiola
*/
#include<bits/stdc++.h>

using namespace std;

class  SegTree{
    vector<int> st;
    vector<int> lazy;
    vector<bool> has;
    int size;

    int el_neutro = 0;

    //Vamos somar a quantidade de piratas do tipo 1
    int f(int a, int b){
        return a + b;
    }

    //Temos 3 tipos de atualização em intervalo, que devemos considerar na propagação:
    //lazy[sti] = 0  => alterar todos para 0
    //lazy[sti] = 1  => alterar todos para 1
    //lazy[sti] = -1 => inverter todos (0 -> 1, 1 -> 0)
     void propagate(int sti, int stl, int str){
        if(has[sti]){
            if (lazy[sti] == 0)
                st[sti] = 0;                //Não sobrou nenhum pirata do tipo 1
            else if (lazy[sti] == 1)
                st[sti] = str - stl + 1;    //Todos se tornaram do tipo 1
            else
                st[sti] = (str - stl + 1) - st[sti];    //Invertemos tudo
            if(stl != str){ //Temos que tomar cuidado aqui com a sobreposição de operações
                if (has[sti*2 + 1] && lazy[sti] == -1)
                {
                    if (lazy[sti*2 + 1] == -1)
                        has[sti*2 + 1] = false;
                    else
                        lazy[sti*2 + 1] = !lazy[sti*2 + 1]; 
                }
                else
                {
                    lazy[sti*2 + 1] = lazy[sti];
                    has[sti*2 + 1] = true;
                }
                
                if (has[sti*2 + 2] && lazy[sti] == -1)
                {
                    if (lazy[sti*2 + 2] == -1)
                        has[sti*2 + 2] = false;
                    else
                        lazy[sti*2 + 2] = !lazy[sti*2 + 2]; 
                }
                else
                {
                    lazy[sti*2 + 2] = lazy[sti];
                    has[sti*2 + 2] = true;
                }
            }
            has[sti] = false;
        }
    }

    int query(int sti, int stl, int str, int l, int r){
        propagate(sti, stl, str);

        if(str < l || r < stl)
            return el_neutro;


        if(stl >= l and str <= r)
            return st[sti];

        int mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }

    void update_range(int sti, int stl, int str, int l,int r, int amm){
        propagate(sti, stl, str);
        if(stl >= l and str <= r){
            lazy[sti] = amm;
            has[sti] = true;
            propagate(sti, stl, str);
            return;
        }

        if(stl > r  or str < l)
            return;
        int mid = (stl + str)/2;
        update_range(sti*2+1,stl,mid,l,r,amm);
        update_range(sti*2+2,mid+1,str,l,r,amm);
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
    }

    //Construir a SegTree dado o vetor inicial
    void build(int sti, int stl, int str, const string &piratas){
        if (stl == str){
            st[sti] = piratas[stl] - '0';
            return;
        }
        int mid = (stl + str)/2;
        build(sti*2+1, stl, mid, piratas);
        build(sti*2+2, mid+1, str, piratas);
        st[sti] = f(st[sti*2+1], st[sti*2+2]);
    }

    void print(int sti, int l, int r, int nivel){
        for(int i = 0; i < nivel; i++)
            cout << "   ";
        cout << sti + 1 << ":" << st[sti] << endl;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        print(sti*2 + 1, l, mid, nivel + 1);
        print(sti*2 + 2, mid + 1, r, nivel + 1);
    }

    public:
        SegTree(int n):  st(4*n,0), lazy(4*n,0),has(4*n,false){size = n;}
        int query(int l, int  r){return query(0,0,size-1,l,r);}
        void update_range(int l, int r, int amm){update_range(0,0,size-1,l,r,amm);}
        void build(string piratas){build(0, 0, size-1, piratas);}
        void print(){print(0, 0, size-1,0);}
};

int main(){
    int T, i, j;
    cin >> T;
    for(int k = 1; k <= T; k++){
        int m, numVezes, n;
        string piratas = "";
        string s;
        cin >> m;
        for(i = 0; i < m; i++){ //Nunca vi uma entrada de dados tão fresca... mas enfim
            cin >> numVezes;
            cin >> s;
            for(j = 0; j < numVezes; j++)
                piratas += s;
        }
        n = piratas.size();
        //Construindo a SegTree e iniciando as operações
        SegTree seg(n);
        int q, a, b, cont = 0;
        char op;
        seg.build(piratas);
        //seg.print();
        //cout << endl;

        cout << "Case " << k << ":" << endl;
        cin >> q;
        for(i = 0; i < q; i++)
        {
            cin >> op >> a >> b;
            if (op == 'F')
                seg.update_range(a, b, 1);
            else if (op == 'E')
                seg.update_range(a, b, 0);
            else if (op == 'I')
                seg.update_range(a, b, -1);
            else
            {
                cont++;
                cout << "Q" << cont << ": " << seg.query(a,b) << endl;
            }
            //seg.print();
            //cout << endl;
        }
    }
}