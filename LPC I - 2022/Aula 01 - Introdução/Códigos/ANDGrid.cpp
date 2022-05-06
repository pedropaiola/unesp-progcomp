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

	int n, m;
	cin >> n >> m;

	vector<string> mat = vector<string>(n);

	for(int i = 0; i < n; i++)
		cin >> mat[i];

	vector<string> red, blue;
	red = blue = mat;

	for(int i = 1; i < m - 1; i++){
		red[0][i] = '#';
		blue[n - 1][i] = '#';
	}

	for(int j = 1; j < m - 1; j++){
		if(j & 1)
			for(int i = 1; i < n - 1; i++)
				red[i][j] = '#';
		else
			for(int i = 1; i < n - 1; i++)
				blue[i][j] = '#';
	}

	for(int i = 0; i < n; i++)
		cout << red[i] << "\n";

	cout << "\n";

	for(int i = 0; i < n; i++)
		cout << blue[i] << "\n";
	
    return 0;
}
