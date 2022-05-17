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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vi arr(n);

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	sort(begin(arr), end(arr));

	ll ans = 0;
	
	for(int i = 0; i < n; i++){
		int upper, lower;
		upper = upper_bound(begin(arr) + i + 1, end(arr), k + arr[i]) - begin(arr);
		lower = lower_bound(begin(arr) + i + 1, end(arr), k + arr[i]) - begin(arr);

		if(lower < upper)
			ans += upper - lower;
	}

	cout << ans << "\n";
	
    return 0;
}