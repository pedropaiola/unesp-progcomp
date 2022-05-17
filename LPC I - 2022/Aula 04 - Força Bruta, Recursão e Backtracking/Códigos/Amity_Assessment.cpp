int main() {
    string str1, str2, aux;
    cin >> str1 >> aux;
    str1 = str1 + aux[1] + aux[0];
    cin >> str2 >> aux;
    str2 = str2 + aux[1] + aux[0];

    int pos;
    vector<string> possible;
    aux = str2;

    for (int i = 0; i < 4; i++) {
        if (aux[i] == 'X')
            pos = i;
    }

    do {
        int i = (pos + 1) % 4;
        swap(aux[pos], aux[i]);
        possible.push_back(aux);
        pos = i;
    } while (aux != str2);

    for (int i = 0; i < possible.size(); i++) {
        if (possible[i] == str1) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";

    return 0;
}
