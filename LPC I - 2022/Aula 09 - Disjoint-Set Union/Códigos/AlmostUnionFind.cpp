#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

void set_io(string s) {
    if (!s.empty()) {
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}

vi parent, len, sum;

int find(int u) {
    if (u == parent[u])
        return u;

    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) {
        if (len[u] < len[v])
            swap(u, v);

        parent[v] = u;
        len[u] += len[v];
        sum[u] += sum[v];
    }
}

void init(int u) {
    parent[u] = sum[u] = u;
    len[u] = 1;
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        parent = len = sum = vi(2 * n + 1);

        for (int u = 0; u <= n; u++)
            init(u);

        for (int i = 0; i < m; i++) {
            int c, p, q, u;
            cin >> c >> p;

            if (c != 3) {
                cin >> q;

                if (c == 2) {
                    u = find(p);
                    sum[u] -= p;
                    len[u]--;
                    init(p);
                }

                p = find(p);
                q = find(q);
                u = p + n > n ? p : p + n;

                unite(u, p);
                unite(u, q);
            } else {
                p = find(p);
                cout << len[p] << " " << sum[p] << "\n";
            }
        }
    }

    return 0;
}