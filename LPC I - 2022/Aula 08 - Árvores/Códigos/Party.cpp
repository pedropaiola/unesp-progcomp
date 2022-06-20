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

int n;
vector<vi> adj;

int dfs(int u, int parent) {
    int counter = 0;

    for (auto v : adj[u]) {
        if (v != parent)
            counter = max(counter, dfs(v, u));
    }

    return counter + 1;
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj = vector<vi>(n + 1);

    vi managers;

    for (int employee = 1; employee <= n; employee++) {
        int manager;
        cin >> manager;

        if (manager != -1)
            adj[manager].push_back(employee);
        else
            managers.push_back(employee);
    }

    int ans = 0;

    for (auto manager : managers)
        ans = max(ans, dfs(manager, -1));

    cout << ans << "\n";

    return 0;
}