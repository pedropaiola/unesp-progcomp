#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF
#define EPSILON
#define PI 3.14159265359

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

ll n;
vi bit;

void update(ll idx, const ll &val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

ll query(ll idx) {
    ll sum = 0;

    while (idx >= 1) {
        sum += bit[idx];
        idx -= idx & -idx;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll q;
    cin >> n >> q;

    vi arr(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> arr[i];

    vi bit(n + 1);

    while (q--) {
        ll op;
        cin >> op;

        if (op == 1) {
            ll k, u;
            cin >> k >> u;
            update(k, u - arr[k]);
            arr[k] = u;
        } else {
            ll l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
        }
    }

    return 0;
}
