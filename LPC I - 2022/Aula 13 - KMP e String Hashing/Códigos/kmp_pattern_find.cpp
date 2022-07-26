#include<bits/stdc++.h>
#define ll long long int
#define MAXN 1000000

using namespace std;

int a[MAXN+1];

void calculatePrefix(const string &B) {
	int i = 0, j = -1;
	a[0] = -1;
    int m = B.size();
	while(i < m){
		while (j >= 0 && B[i] != B[j])
			j = a[j];
		i++; j++;
		a[i] = j;
	}
}

vector<int> KMP(const string &A, const string &B){
    vector<int> resp;
	int i = 0, j = 0;
    int n = A.size(), m = B.size();
	calculatePrefix(B);
	while(i < n){
		while(j >= 0 && A[i] != B[j])
			j = a[j];
		j++; i++;
		if(j == m){
			resp.push_back(i - m);
            j = a[j];
        }
	}
	return resp;
}


int main(){
    int t;
    string A, B;
    cin >> t;
    while(t--){
        cin >> A >> B;

        vector<int> pos = KMP(A, B);

        if (pos.size() == 0)
            cout << "Not Found\n\n";
        else
        {
            cout << pos.size() << endl;
            for(auto i : pos)
                cout << (i+1) << " ";
            cout << "\n\n";
        }
    }
}