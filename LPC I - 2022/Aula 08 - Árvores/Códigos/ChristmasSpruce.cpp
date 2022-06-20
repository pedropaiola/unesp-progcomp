#include <bits/stdc++.h>

#define MAX
#define MOD 1000000007
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

vector<vi> adj;

bool dfs(int u, int parent) {
    int children, counter;
    children = adj[u].size();
    counter = 0;

    for (auto v : adj[u]) {
        if (v != parent) {
            if (adj[v].size() == 0)
                counter++;

            if (!dfs(v, u))
                return false;
        }
    }

    if (children != 0 && counter < 3)
        return false;

    return true;
}

void add_edge(const int &u, const int &v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj = vector<vi>(n + 1);

    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        add_edge(u, v);
    }

    cout << (dfs(1, -1) ? "Yes\n" : "No\n");

    return 0;
}