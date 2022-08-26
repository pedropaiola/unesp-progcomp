#include <bits/stdc++.h>
#define ll long long int
#define MAXN 100001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, a, l, r;
    int p[MAXN];
    cin >> n;
    p[0] = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        p[i+1] = p[i] + a;
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        cout << (p[r] - p[l-1]) << "\n";
    }
}