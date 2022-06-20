#include <bits/stdc++.h>

#define MAX
#define MOD 1000000007
#define INF

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

void set_io(string s) {
    if (!s.empty()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

ll n, k, d;
vector<vi> dp;

ll solve(ll weight, bool flag) {
    ll &sum = dp[weight][flag];

    if (sum != -1)
        return sum;
    else if (weight == n && flag)
        return 1;

    sum = 0;

    for (ll i = 1; i <= k && weight + i <= n; i++) {
        if (i >= d)
            sum = (sum + solve(weight + i, true)) % MOD;
        else
            sum = (sum + solve(weight + i, flag)) % MOD;
    }

    return sum;
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> d;
    dp = vector<vi>(n + 1, vi(2, -1));

    cout << solve(0, false) << "\n";

    return 0;
}