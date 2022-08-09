#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k, p, i;
    string s;
    string possib[500];

    cin >> n >> m >> k;
    cin >> s;
    for(i = 0; i < m; i++){
        cin >> possib[i];
        sort(possib[i].begin(), possib[i].end());
    }
    cin >> p;
    p--;

    int j = m-1;
    for(i = n-1; i >= 0; i--){
        if (s[i] == '#'){
            s[i] = possib[j][p % k];
            p = p / k;
            j--;
        }
    }
    cout << s << "\n";
}