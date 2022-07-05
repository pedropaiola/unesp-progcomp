#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<vector<ll>> adj;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        adj = vector<vector<ll>>(n + 1);
        for (int i = 1; i < n; i++)
        {
            int m;
            cin >> m;
            ll a;
            for (int j = 0; j < m; j++)
            {
                cin >> a;
                adj[i].push_back(a); // Grafo direcionado
            }
            sort(adj[i].begin(), adj[i].end());
        }

        queue<ll> p;
        p.push(1);
        bool fim = false;
        vector<int> vis(n + 1);
        vector<int> pai(n + 1);
        // Começando a BFS
        while (!p.empty())
        {
            ll x = p.front();
            p.pop();
            for (int i = 0; i < adj[x].size(); i++)
            {
                if (vis[adj[x][i]])
                    continue;
                vis[adj[x][i]] = true;
                p.push(adj[x][i]);
                pai[adj[x][i]] = x;
                if (adj[x][i] == n)
                {
                    fim = true;
                    break;
                }
            }
        }
        vector<int> res;
        if (!fim)
            cout << "-1\n";
        else
        {
            int pos = pai[n];
            // res.push_back(n);
            while (pos != 1)
            {
                res.push_back(pos);
                pos = pai[pos];
            }
            res.push_back(1);
            cout << res.size() << "\n";
            for (int i = res.size() - 1; i >= 0; i--)
            {
                cout << res[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}