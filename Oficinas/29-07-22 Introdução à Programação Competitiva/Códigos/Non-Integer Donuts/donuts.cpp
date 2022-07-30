#include <bits/stdc++.h>

using namespace std;

int main() {
    char aux;
    int n, inteiro, decimal, centavos, atrasado = 0;
    cin >> n;
    cin >> aux >> inteiro >> aux >> decimal;
    centavos = decimal;

    for (int i = 0; i < n; i++) {
        cin >> aux >> inteiro >> aux >> decimal;
        centavos = (centavos + decimal) % 100;

        if (centavos != 0) {
            atrasado++;
        }
    }

    cout << atrasado << "\n";

    return 0;
}