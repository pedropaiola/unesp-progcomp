#include<bits/stdc++.h>

using namespace std;

int main(){
    int d, a, n;
    cin >> d >> a >> n;
    if (n > 15)
        cout << (32 - n) * (d + 14*a) << "\n";
    else
        cout << (32 - n) * (d + (n-1)*a) << "\n";
}