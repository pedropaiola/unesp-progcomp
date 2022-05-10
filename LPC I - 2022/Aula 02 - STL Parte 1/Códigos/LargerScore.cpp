#include <bits/stdc++.h>

#define MAX 1e18
#define MOD
#define INF

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

bool cmp(const ii &a, const ii &b){
    if(a.first == b.first)
        return a.second > b.second;

    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    vii arr(n);

    for(ll i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(begin(arr), end(arr), cmp);

    ll mi = MAX;
    priority_queue<ll> pq;
        
    for(int i = 0; i < n; i++){
        int idx = arr[i].second;

        if(idx >= k){
            if(!pq.empty())
                mi = min(mi, arr[i].second - pq.top());
        }
        else
            pq.push(idx);
    }

    cout << (mi == MAX ? -1 : mi) << "\n";

    return 0;
}
