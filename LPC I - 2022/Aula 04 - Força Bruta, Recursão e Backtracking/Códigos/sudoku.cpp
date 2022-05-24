#include <bits/stdc++.h>

#define MAX
#define MOD
#define INF

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

int n;
vector<vector<int>> sudoku;

bool verifica(int row, int col, int elem) {
    for (int i = 0; i < n; i++) {
        // verificar se existem elementos repetidos na linha
        if (sudoku[i][col] == elem)
            return false;
        // verificar se existem elementos repetidos na coluna
        else if (sudoku[row][i] == elem)
            return false;
    }

    int sq, sub_row, sub_col;
    sq = sqrt(n);
    sub_row = row / sq * sq;
    sub_col = col / sq * sq;

    // verificar se existem elementos repetidos no subquadrado
    for (int i = sub_row; i < sub_row + sq; i++) {
        for (int j = sub_col; j < sub_col + sq; j++) {
            if (sudoku[i][j] == elem)
                return false;
        }
    }

    return true;
}

bool solve(int row, int col) {
    if (col == n) {
        col = 0;
        row++;

        if (row == n)
            return true;
    }

    if (sudoku[row][col] == 0) {
        for (int i = 1; i <= n; i++) {
            if (verifica(row, col, i)) {
                sudoku[row][col] = i;

                if (solve(row, col + 1))
                    return true;
            }
        }

        sudoku[row][col] = 0;
    } else
        return solve(row, col + 1);

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool f = false;

    while (cin >> n) {
        if (f)
            cout << "\n";

        f = true;

        n *= n;
        sudoku = vector<vector<int>>(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> sudoku[i][j];

        if (solve(0, 0)) {
            for (int i = 0; i < n; i++) {
                cout << sudoku[i][0];

                for (int j = 1; j < n; j++)
                    cout << " " << sudoku[i][j];

                cout << "\n";
            }
        } else
            cout << "NO SOLUTION\n";
    }

    return 0;
}
