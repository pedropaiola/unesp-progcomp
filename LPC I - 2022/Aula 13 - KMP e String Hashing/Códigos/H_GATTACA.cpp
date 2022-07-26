//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2507
#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF 10000000000

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
int x = uniform_int_distribution<int>(0, mod - 1)(rng);

struct hash_str
{
    vector<ll> h, p;
    hash_str(string s) : h(s.size()), p(s.size())
    {
        int n = s.size();
        h[0] = s[0];
        for (int i = 1; i < n; i++)
        {
            h[i] = (h[i - 1] * x + s[i]) % mod;
        }

        p[0] = 1;
        for (int i = 1; i < n; i++)
        {
            p[i] = (p[i - 1] * x) % mod;
        }
    }
    ll sub_hash(ll l, ll r)
    {
        if (l == 0)
        {
            return h[r];
        }
        ll ans = (h[r] - h[l - 1] * p[r - l + 1]) % mod;
        if (ans < 0)
            ans += mod;

        return ans;
    }
};

int main()
{
    ll t;
    cin >> t;
    string palavra;
    while (t--)
    {
        cin >> palavra;
        hash_str hs(palavra);
        ll n = palavra.size();
        ll ini = 1, fim = n;
        ll tam = 0;
        while (ini <= fim)
        {
            ll mid = ini + (fim - ini) / 2;

            map<ll, ll> mp;
            bool f = false;
            for (int i = 0; i < n; i++)
            {
                if (i + mid - 1 >= n)
                    break;
                mp[hs.sub_hash(i, i + mid - 1)]++;
                if (mp[hs.sub_hash(i, i + mid - 1)] >= 2)
                {
                    f = true;
                    break;
                }
            }
            if (f)
            {
                tam = mid;
                ini = mid + 1;
            }
            else
            {
                fim = mid - 1;
            }
        }
        if (tam == 0)
        {
            cout << "No repetitions found!\n";
        }
        else
        {
            map<ll, pair<ll, string>> mp;
            map<ll, pair<ll, string>>::iterator itr;
            string s;
            for (int i = 0; i < n; i++)
            {
                if (i + tam - 1 >= n)
                    break;
                ll a;
                tie(a, s) = mp[hs.sub_hash(i, i + tam - 1)];
                if (a == 0)
                {
                    s = palavra.substr(i,tam);
                    mp[hs.sub_hash(i, i + tam - 1)] = {1, s};
                }
                else
                    mp[hs.sub_hash(i, i + tam - 1)] = {a + 1, s};
            }
            map<string, ll> ans;

            for (itr = mp.begin(); itr != mp.end(); ++itr)
            {
                ll a;
                tie(a, s) = mp[itr->first];
                if (a >= 2)
                    ans[s] = a;
            }
            for (auto x : ans)
            {
                cout << x.first << " " << x.second << "\n";
                break;
            }
        }
    }
    return 0;
}