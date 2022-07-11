#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF
#define EPSILON 1e-7

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

double x;
vi parent, len;
vector<tuple<ii, ll, ll>> edges;

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

void kruskal(ll &p, ll &q) {
    for (auto [w, u, v] : edges) {
        u = find(u);
        v = find(v);

        if (u != v) {
            unite(u, v);
            p += w.first;
            q += w.second;
        }
    }
}

void add_edge(const ll &u, const ll &v, const ll &a, const ll &b) {
    edges.push_back({{a, b}, u, v});
}

bool cmp(tuple<ii, ll, ll> a, tuple<ii, ll, ll> b) {
    ii p, q;
    p = get<0>(a);
    q = get<0>(b);

    return (p.first - p.second * x) > (q.first - q.second * x);
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    parent = len = vi(n + 1);

    for (ll i = 0; i < m; i++) {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        add_edge(u, v, a, b);
    }

    ll p, q, gcd;
    double left = 0., right = 1e7;

    while (fabs(right - left) >= EPSILON) {
        x = (left + right) / 2;

        for (ll i = 0; i <= n; i++) {
            parent[i] = i;
            len[i] = 1;
        }

        p = q = 0;

        sort(begin(edges), end(edges), cmp);
        kruskal(p, q);

        if (p >= q * x) {
            left = x;
        } else {
            right = x;
        }
    }

    gcd = __gcd(p, q);
    p /= gcd;
    q /= gcd;

    cout << p << "/" << q << "\n";

    return 0;
}