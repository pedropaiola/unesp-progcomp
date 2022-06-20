#include <bits/stdc++.h>
using namespace std;
#define no_tle_pls               \
    ios::sync_with_stdio(false); \
    cin.tie(0)
typedef long long int ll;

ll LIS(vector<ll> dp)
{
    vector<ll> lis;
    lis.push_back(dp[0]);

    for (int i = 1; i < dp.size(); i++)
    {
        int num = dp[i];

        if (num)
        {
            if (num <= lis.back())
            {
                int idx = lower_bound(begin(lis), end(lis), num) - begin(lis);
                lis[idx] = num;
            }
            else
                lis.push_back(num);
        }
    }
    ll tam = lis.size();
    return max((ll)0, tam - 1);
}

ll DP(vector<ll> &a, vector<ll> &b, map<ll, ll> pos)
{
    ll tam = max(a.size(), b.size());

    vector<ll> dp(b.size());

    for (int i = 0; i < b.size(); i++)
    {
        if (binary_search(a.begin(), a.end(), b[i]))
        {
            ll x = pos[b[i]];
            dp[i] = x;
        }
    }
    return LIS(dp);
}

int main()
{
    no_tle_pls;

    int t;
    cin >> t;
    int z = 0;
    while (t--)
    {
        z++;

        ll n, p, q;

        cin >> n >> p >> q;
        p += 1;
        q += 1;
        vector<ll> p1(p + 1);
        vector<ll> p2(q + 1);
        map<ll, ll> pos;

        for (int i = 1; i <= p; i++)
        {
            cin >> p1[i];
            pos[p1[i]] = i;
        }
        sort(p1.begin(), p1.end());

        for (int i = 1; i <= q; i++)
        {
            cin >> p2[i];
        }

        cout << "Case " << z << ": " << DP(p1, p2, pos) << "\n";
    }

    return 0;
}