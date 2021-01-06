/*
Problema: Living with Courage
Categorias:
	data structure > segment tree
Dificuldade: facil
Descricao:
Dica:
Autor: Paiola
*/

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

class  SegTree{
    vector<ll> st;
    vector<ll> stMin;
    ll size;

    ll el_neutro = 0;
    ll el_neutro_min = LLONG_MAX;

    ll f(ll a, ll b){
        return a + b;
    }

    ll g(ll a, ll b){
        return min(a,b);
    }

    ll query(ll sti, ll stl, ll str, ll l, ll r){
        if(str < l || r < stl)
            return el_neutro;


        if(stl >= l and str <= r)
            return st[sti];

        ll mid = (str+stl)/2;

        return f(query(sti*2+1,stl,mid,l,r),query(sti*2+2,mid+1,str,l,r));
    }

    ll queryMin(ll sti, ll stl, ll str, ll l, ll r){
        if(str < l || r < stl)
            return el_neutro_min;


        if(stl >= l and str <= r)
            return stMin[sti];

        ll mid = (str+stl)/2;

        return g(queryMin(sti*2+1,stl,mid,l,r),queryMin(sti*2+2,mid+1,str,l,r));
    }

    void update(ll sti, ll stl, ll str, ll i, ll amm){
        if(stl == i and str == i){
            st[sti] += amm;
            stMin[sti] += amm;
            return;
        }

        if(stl > i or str < i)
            return;
        ll mid = (stl + str)/2;
        update(sti*2+1,stl,mid,i,amm);
        update(sti*2+2,mid+1,str,i,amm);
        st[sti] = f(st[sti*2+1],st[sti*2+2]);
        stMin[sti] = g(stMin[sti*2+1],stMin[sti*2+2]);
    }

    void build(ll sti, ll stl, ll str, ll vetor[]){
        if (stl == str){
            st[sti] = vetor[stl];
            stMin[sti] = vetor[stl];
            return;
        }
        ll mid = (stl + str)/2;
        build(sti*2+1, stl, mid, vetor);
        build(sti*2+2, mid+1, str, vetor);
        st[sti] = f(st[sti*2+1], st[sti*2+2]);
        stMin[sti] = g(stMin[sti*2+1],stMin[sti*2+2]);
    }


    public:
        SegTree(ll n):  st(4*n,0), stMin(4*n, 0){size = n;}
        ll query(ll l, ll  r){return query(0,0,size-1,l,r);}
        ll queryMin(ll l, ll  r){return queryMin(0,0,size-1,l,r);}
        void update(ll i, ll amm){update(0,0,size-1,i,amm);}
        void build(ll vetor[]){build(0, 0, size-1, vetor);}
};

int main(){
    ll n, p, x, y, i;
    ll v[100000];
    string op;

    cin >> n;
    SegTree seg(n);
    for(i = 0; i < n; i++){
        cin >> v[i];
    }
    seg.build(v);
    cin >> p;
    while(p--){
        cin >> op >> x >> y;
        if (op == "COUNT")
            cout << seg.query(x, y) - seg.queryMin(x,y) << endl;
        else if (op == "GROW")
            seg.update(y, x);
        else
            seg.update(y, -x);
    }
}