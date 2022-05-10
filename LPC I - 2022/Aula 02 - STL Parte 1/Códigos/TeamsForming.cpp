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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vi students(n);

	for(int i = 0; i < n; i++)
		cin >> students[i];

	sort(begin(students), end(students));

	int problems = 0;
	
	for(int i = 0; i < n; i += 2)
		problems += students[i + 1] - students[i];

	cout << problems << "\n";
	
    return 0;
}
