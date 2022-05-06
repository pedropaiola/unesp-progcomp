#include<bits/stdc++.h>

using namespace std;

int main(){
    string ent;
    int n, i;
    vector<char> resp;

    getline(cin, ent);
    n = ent.size();

    for(i = 0; i < n; i++)
    {
        if (resp.empty() || ent[i] != resp.back())
        {
            resp.push_back(ent[i]);
        }
        else
        {
            resp.pop_back();
        }
    }
    n = resp.size();
    for(i = 0; i < n; i++)
        cout << resp[i];
    
    cout << endl;
}