#include <bits/stdc++.h>
 
#define MAX
#define MOD
#define INF
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n, m;
    cin >> n >> m;
 
    vi tree(n);
 
    for(ll i = 0; i < n; i++)
        cin >> tree[i];
 
    ll left = 0, right = *max_element(begin(tree), end(tree)), mi = 0;
 
    while(left <= right){
        ll mid = (left + right) / 2, w = 0;
 
        for(ll i = 0; i < n; i++)
            w += max(0LL, tree[i] - mid);
 
        if(w >= m){
            mi = max(mi, mid);
            left = mid + 1;
        } else
            right = mid - 1;
    }
 
    cout << mi << "\n";
 
    return 0;
}
 