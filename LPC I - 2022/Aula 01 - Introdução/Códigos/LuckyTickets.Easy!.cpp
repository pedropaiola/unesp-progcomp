#include <bits/stdc++.h>
 
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
typedef long long ll;
using namespace std;

ll n;
vector<ll> v;
ll brute(){
    if(v.size() == n){
        ll soma1 = 0, soma2 = 0;
        for(int j = 0; j < n; j++){
            if(j < n/2)soma1 += v[j];
            if(j >= n/2)soma2 += v[j];
        }
        if(soma1 == soma2)return 1;
        return 0;
    }
    ll res = 0;
    for(int j = 0; j <= 9; j++){
        v.push_back(j);
        res += brute();
        v.pop_back();
    }
    return res;
}
int main(){
    v.clear();
    cin >> n;
    cout << brute() << "\n";
    return 0;
}