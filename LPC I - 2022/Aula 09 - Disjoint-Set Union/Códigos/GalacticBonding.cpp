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

struct disjoint_set {
    int n;
    vi parent, len;

    disjoint_set(int n) {
        this->n = n;
        parent = len = vi(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            len[i] = 1;
        }
    }

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
        }
    }
};

double euclidean(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    set_io("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        double d;
        cin >> n >> d;

        disjoint_set dsu(n + 1);
        vector<double> x(n + 1), y(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> x[i] >> y[i];

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                double distance = euclidean(x[i], y[i], x[j], y[j]);

                if (distance <= d)
                    dsu.unite(j, i);
            }
        }

        set<int> ans;

        for (int i = 1; i <= n; i++) {
            dsu.find(i);
            ans.insert(dsu.parent[i]);
        }

        cout << "Case " << t << ": " << ans.size() << "\n";
    }

    return 0;
}