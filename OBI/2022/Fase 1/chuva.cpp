#include<bits/stdc++.h>
#define MAXN 100000

using namespace std;

int main(){
    int n, s, i, j;
    int x[MAXN], p[MAXN+1];
    map<int, int> qtde;
    int res = 0;

    cin >> n >> s;
    p[0] = 0;
    qtde[0] = 1;
    for(i = 0; i < n; i++){
        cin >> x[i];
        p[i+1] = p[i] + x[i];
        if (p[i+1] >= s)
            res += qtde[p[i+1] - s];
        qtde[p[i+1]]++;
    }

    cout << res << "\n";
}