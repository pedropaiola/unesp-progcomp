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

ll k;
char first, last;
vector<vector<vector<vi>>> dp;
map<string, ll> mp;

ll solve(ll w, ll x, ll y, ll z, char backend) {
    if (w + x + y + z == k)
        return backend == first;
    else if (dp[w][x][y][z] != -1)
        return dp[w][x][y][z];

    ll sum = 0;

    for (auto it : mp) {
        ll qt = it.second;
        string str = it.first;

        if (str == "AA" && w < qt && backend == 'A')
            sum += solve(w + 1, x, y, z, 'A');
        else if (str == "AB" && x < qt && backend == 'A')
            sum += solve(w, x + 1, y, z, 'B');
        else if (str == "BB" && y < qt && backend == 'B')
            sum += solve(w, x, y + 1, z, 'B');
        else if (str == "BA" && z < qt && backend == 'B')
            sum += solve(w, x, y, z + 1, 'A');
    }

    return dp[w][x][y][z] = sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    string l;
    cin >> n >> k >> l;
    first = l[0];
    last = l[1];

    for (ll i = 0; i < n; i++) {
        string str;
        cin >> str;
        mp[str]++;
    }

    dp = vector<vector<vector<vi>>>(mp["AA"] + 1,
                                    vector<vector<vi>>(mp["AB"] + 1,
                                                       vector<vi>(mp["BB"] + 1,
                                                                  vi(mp["BA"] + 1, -1))));

    ll ans = solve(0, 0, 0, 0, last);

    if (ans)
        cout << "YES\n"
             << ans << "\n";
    else
        cout << "NO\n";

    return 0;
}