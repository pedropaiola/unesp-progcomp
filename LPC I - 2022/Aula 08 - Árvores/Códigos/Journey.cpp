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
vector<double> dp;

double dfs(int u, int parent) {
    double counter, average;
    counter = average = 0.;

    for (auto v : adj[u]) {
        if (v != parent) {
            average += dfs(v, u);
            counter++;
        }
    }

    if (counter == 0)
        return 1.;

    return average / counter + 1;
}

void add_edge(const int &u, const int &v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj = vector<vi>(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    cout << fixed << setprecision(15) << dfs(1, -1) - 1 << "\n";

    return 0;
}