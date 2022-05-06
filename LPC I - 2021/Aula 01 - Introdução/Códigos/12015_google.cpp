#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, p;
    vector<string> sites;
    string url;
    int relevMax;
    cin >> t;
    for(int i = 1; i <= t; i++){
        relevMax = 0;
        for(int j = 0; j < 10; j++){
            cin >> url >> p;
            if (p > relevMax)
            {
                sites.clear();
                sites.push_back(url);
                relevMax = p;
            } 
            else if (p == relevMax)
                sites.push_back(url);
        }
        cout << "Case #" << i << ":" << endl;
        for(int j = 0; j < (int)sites.size(); j++)
            cout << sites[j] << endl;
    }

}