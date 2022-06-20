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

void set_io(string s) {
    if (!s.empty()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

ll n, diameter;
vi height;
vector<vi> adj;

ll dfs(ll u, ll parent) {
    ll h1, h2;
    h1 = h2 = 0;

    for (auto v : adj[u]) {
        if (v != parent) {
            height[u] = max(height[u], dfs(v, u) + 1);

            if (height[v] > h2) {
                h2 = height[v];

                if (h2 > h1)
                    swap(h1, h2);
            }
        }
    }

    diameter = max(diameter, h1 + h2);

    return height[u];
}

void add_edge(const ll &u, const ll &v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj = vector<vi>(n + 1);

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    height = vi(n + 1, 1);
    diameter = 0;

    dfs(1, -1);

    cout << diameter << "\n";

    return 0;
}