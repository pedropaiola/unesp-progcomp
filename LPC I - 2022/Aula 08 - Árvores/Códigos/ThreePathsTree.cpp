#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF 1e7

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

int n, a, b, c;
vi depth, parent;
vector<vi> adj;

void dfs(int u, int p) {
    parent[u] = p;

    for (auto v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int bfs(const vi &sources) {
    queue<int> q;
    vi dist(n + 1, INF);

    for (auto source : sources) {
        q.push(source);
        dist[source] = 0;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int ma = 0;

    for (int u = 1; u <= n; u++) {
        if (dist[u] >= ma && u != a && u != b) {
            ma = dist[u];
            c = u;
        }
    }

    return ma;
}

void add_edge(const int &u, const int &v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj = vector<vi>(n + 1);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    parent = depth = vi(n + 1);

    dfs(1, -1);

    for (int u = 1, ma = 0; u <= n; u++) {
        if (depth[u] > ma) {
            ma = depth[u];
            a = u;
        }
    }

    parent = depth = vi(n + 1);

    dfs(a, -1);

    for (int u = 1, ma = 0; u <= n; u++) {
        if (depth[u] > ma) {
            ma = depth[u];
            b = u;
        }
    }

    int p = b;
    vi sources;

    while (p != -1) {
        sources.push_back(p);
        p = parent[p];
    }

    cout << depth[b] + bfs(sources) << "\n"
         << a << " " << b << " " << c << "\n";

    return 0;
}