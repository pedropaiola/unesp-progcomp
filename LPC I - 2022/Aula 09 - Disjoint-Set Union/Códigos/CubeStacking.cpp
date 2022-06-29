#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const ll maxn = 30005;

    vector<int>pai;
    vector<int>tam;
    vector<int>ant;

int find(int x){
    if(x==pai[x]){
        return x;
    }     
    ll temp = find(pai[x]);
    ant[x] += ant[pai[x]];
    return pai[x] = temp;
}

void unir(int a, int b){
    int x = find(a), y = find(b);

    pai[y] = x;
    ant[y]+= tam[x];
    tam[x]+=tam[y];

}


int main()
{
    fast_io;
    
    pai = vector<int>(maxn+1);
    tam = vector<int>(maxn+1,1);
    ant = vector<int>(maxn+1);

    for(int i=1;i<maxn;i++){
        pai[i] = i;
    }

    int q;
    cin >> q;
    char c;
    int a,b;

    while(q--){
        cin >> c;
        if(c=='M'){
            cin >> a >> b;
            unir(a,b);
        }else{
            cin >> a;
            ll pos = find(a);
            cout << tam[pos] - ant[a] - 1 << "\n";
        }    
    }

    return 0;
}