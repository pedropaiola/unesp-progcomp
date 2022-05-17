#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF 1e17

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

double euclidean(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        if (n == 0)
            break;

        vector<double> x(n), y(n);

        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i];

        double mi = INF;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = sqrt(euclidean(x[i], y[i], x[j], y[j]));
                mi = min(mi, dist);
            }
        }

        cout << fixed << setprecision(4);
        
        if(mi < 10000)
            cout << mi << "\n";
        else
            cout << "INFINITY\n";
    }

    return 0;
}
