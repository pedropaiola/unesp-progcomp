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

int n;
vii parent;
vector<vi> adj;
vector<iii> edges;

void bfs(const vi &sources) {
    queue<int> q;
    vector<int> dist(n + 1, INF);
    parent = vii(n + 1, {-1, -1});

    for (auto s : sources) {
        dist[s] = 0;
        q.push(s);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto i : adj[node]) {
            int u, v, w;
            tie(u, v, w) = edges[i];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = {u, i / 2};
                q.push(v);
            }
        }
    }
}

void add_edge(int u, int v) {
    adj[u].push_back(edges.size());
    edges.push_back({u, v, 1});
    adj[v].push_back(edges.size());
    edges.push_back({v, u, 1});
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, d;
    cin >> n >> k >> d;
    adj = vector<vi>(n + 1);

    vi police_stations;

    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        police_stations.push_back(u);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    bfs(police_stations);

    int ans = 0;
    vector<bool> used(n + 1);

    for (int i = 1; i <= n; i++) {
        int u, idx;
        tie(u, idx) = parent[i];

        while (u != -1 && !used[idx]) {
            ans++;
            used[idx] = true;
            tie(u, idx) = parent[u];
        }
    }

    cout << (n - 1) - ans << "\n";

    for (int i = 0; i < n - 1; i++) {
        if (!used[i])
            cout << i + 1 << " ";
    }

    cout << "\n";

    return 0;
}