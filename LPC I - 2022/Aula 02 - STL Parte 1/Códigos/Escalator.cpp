#include <bits/stdc++.h>
 
#define MAX
#define MOD
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
void setIO(string s){
    if (!s.empty()){
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}
 
int main(){
    setIO("");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    vector<queue<int>> q (2);
    int n, time, ans = 0;
	bool side, trip;
    cin >> n >> time >> side;
    q[side].push(time);
	trip = side;
 
    for(int i = 1; i < n; ++i){
        cin >> time >> side;
        q[side].push(time);
    } 
 
    while(!q[0].empty() || !q[1].empty()){
		if(q[trip].empty() || (q[trip].front() > ans + 10 && 
			(!q[!trip].empty() && q[!trip].front() < q[trip].front()))){
			ans += 10;
			trip = !trip;
		}
 
		if(q[trip].front() > ans)
			ans = q[trip].front();
 
		q[trip].pop();
	}
 
    cout << ans + 10 << "\n";
 
    return 0;
}