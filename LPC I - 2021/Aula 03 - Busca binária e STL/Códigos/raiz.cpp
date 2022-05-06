#include<bits/stdc++.h>

using namespace std;

double raiz(double x, double eps=1e-3){
    double l = 0, r = x;
    double m;
    while (r-l > eps){
        m = (l+r)/2;
        cout << "   " << m << endl;
        if (m*m < x)
            l = m;
        else
            r = m;
    }
    return (l+r)/2;
}

int main(){
    double x;
    while(cin >> x){
        cout << "sqrt(" << x << ") = " << sqrt(x) << endl;
        double res = raiz(x);
        cout << "raiz(" << x << ") = " << res << endl;
    }
}