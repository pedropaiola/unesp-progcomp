#include <bits/stdc++.h>

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef long long ll;

using namespace std;
const ll mod = 1e9 + 7;

int main() {
    fast_io;
    string str;

    while (getline(cin, str)) {
        ll num;
        vector<ll> arr;
        stringstream ss(str);

        while (ss >> num) arr.push_back(num);

        stack<pair<ll,ll>> p;
        bool flag = true;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] < 0){
                p.push({-arr[i] , 0});
            }
            else{
                if(p.empty() || p.top().first != arr[i] || p.top().second >= p.top().first){
                    flag = false;
                    break;
                }
                ll x = p.top().first;
                p.pop();
                if(!p.empty()){
                    pair<ll,ll> val = p.top();
                    p.pop();
                    val.second += x;
                    p.push(val);
                }
            }
        }
        if(!p.empty() || !flag)cout << ":-( Try again.\n";
        else cout << ":-) Matrioshka!\n";
    
    }
    

}
