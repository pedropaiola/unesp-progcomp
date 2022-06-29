#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

vector<int>pai;

vector<int>used;
vector<int>ans;

int pos;
void find(int x){
    vector<int>cur;
    int sum = 0;
    while(!used[x]){
        cur.push_back(x);
        used[x] = true;
        x = pai[x];
    }
    for(int i=0;i<cur.size();i++){
        ans[cur[i]] = int(cur.size());
    }

}

int main()
{
    fast_io;
    int q;
    cin >> q;
    
    for(int i=0;i<q;i++){
        int n;
        cin >> n;
        pai = vector<int>(n+1);

        int x =0 ;
        for(int i=1;i<=n;i++){
            cin >> pai[i];
        }
        used = vector<int>(n+1);
        ans = vector<int>(n+1);
        for(int i=1;i<=n;i++){
            if(!used[i]){
                find(i);
            }
        }

        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    



    return 0;
}