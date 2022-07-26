#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF 1e7
#define EPSILON

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
vector<viii> adj;
map<string, int> mp;

int dijkstra(const int &s, const int &d) {
    vector<vi> dist(n + 1, vi(27, INF));
    priority_queue<iii, viii, greater<iii>> pq;
    pq.push({dist[s][26] = 0, s, 26});

    while (!pq.empty()) {
        int du, u, cha;
        tie(du, u, cha) = pq.top();
        pq.pop();

        for (auto edge : adj[u]) {
            int v, w, c;
            tie(v, w, c) = edge;

            if (c != cha && dist[u][cha] + w < dist[v][c]) {
                dist[v][c] = dist[u][cha] + w;
                pq.push({dist[v][c], v, c});
            }
        }
    }

    int mi = INF;

    for (int i = 0; i < 26; i++) {
        mi = min(mi, dist[d][i]);
    }

    return mi;
}

void add_edge(const int &u, const int &v, const int &w, const int &c) {
    adj[u].push_back({v, w, c});
    adj[v].push_back({u, w, c});
}

void add_node(const string &str) {
    if (!mp.count(str)) {
        mp[str] = ++n;
    }
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;

    while (cin >> m) {
        if (m == 0) {
            break;
        }

        n = 0;
        mp.clear();

        string o, d;
        vector<tuple<int, int, string>> edge(m);
        cin >> o >> d;
        add_node(o);
        add_node(d);

        for (int i = 0; i < m; i++) {
            string u, v, str;
            cin >> u >> v >> str;
            add_node(u);
            add_node(v);
            edge[i] = {mp[u], mp[v], str};
        }

        adj = vector<viii>(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            string str;
            tie(u, v, str) = edge[i];
            add_edge(u, v, int(str.size()), str[0] - 'a');
        }

        int letters = dijkstra(mp[o], mp[d]);

        if (letters != INF) {
            cout << letters << "\n";
        } else {
            cout << "impossivel\n";
        }
    }

    return 0;
}