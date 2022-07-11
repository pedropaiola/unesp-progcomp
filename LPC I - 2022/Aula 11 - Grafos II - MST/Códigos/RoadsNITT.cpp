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

vi parent, len;

ll find(ll u) {
    if (parent[u] == u)
        return u;

    return parent[u] = find(parent[u]);
}

void unite(ll u, ll v) {
    if (len[u] < len[v])
        swap(u, v);

    parent[v] = u;
    len[u] += len[v];
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;
        parent = len = vi(n + 1);

        for (ll i = 1; i <= n; i++) {
            parent[i] = i;
            len[i] = 1;
        }

        vii edges(n);

        for (ll i = 1; i < n; i++) {
            ll u, v;
            cin >> u >> v;
            edges[i] = {u, v};
        }

        ll q;
        cin >> q;

        vector<bool> used(n);
        vi queries(q);

        for (ll i = 0; i < q; i++) {
            char op;
            ll id = -1;
            cin >> op;

            if (op == 'R') {
                cin >> id;
                used[id] = true;
            }

            queries[i] = id;
        }

        ll conn = 0;

        for (ll i = 1; i < n; i++) {
            if (!used[i]) {
                int u, v;
                tie(u, v) = edges[i];
                u = find(u);
                v = find(v);

                if (u != v) {
                    conn += len[u] * len[v];
                    unite(u, v);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            find(i);
        }

        ll tot = n * (n - 1) / 2 - conn;
        stack<ll> ans;

        for (ll i = q - 1; i >= 0; i--) {
            ll id = queries[i];

            if (id != -1) {
                ll u, v;
                tie(u, v) = edges[id];
                u = find(u);
                v = find(v);

                if (u != v) {
                    tot -= len[u] * len[v];
                    unite(u, v);
                }
            } else {
                ans.push(tot);
            }
        }

        while (!ans.empty()) {
            cout << ans.top() << "\n";
            ans.pop();
        }

        cout << "\n";
    }

    return 0;
}