#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, i;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        stack<char> p;
        for(i = 0; i < s.size(); i++)
        {
            if ((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
                p.push(s[i]);
            else if (p.empty())
                break;
            else if ((s[i] == ')' && p.top() == '(') || 
                     (s[i] == ']' && p.top() == '[') || 
                     (s[i] == '}' && p.top() == '{'))
                p.pop();
            else
                break;
        }
        if ((i == s.size()) && p.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}