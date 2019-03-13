#include <bits/stdc++.h>
using namespace std;
ifstream fin("sudoku.in");
ofstream fout("sudoku.out");
int a[10][10];
bool pos(int a[10][10], int &i, int &j);
bool verif(int a[10][10], int i, int j, int n);
bool rez(int a[10][10]);
int main() {
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
            fin >> a[i][j];

    rez(a);

    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++)
            fout << a[i][j] << ' ';

        fout << '\n';
    }

    return 0;
}
bool verif(int a[10][10], int i, int j, int n) {
    for(int t = 1; t <= 9; t++)
        if(a[i][t] == n || a[t][j] == n)
            return 0;

    int x = ((i - 1) / 3) * 3;
    int y = ((j - 1) / 3) * 3;

    for(int k = x+1; k <= x + 3; k++)
        for(int t = y+1; t <= y + 3; t++)
            if(a[k][t] == n)
                return 0;

    return 1;
}
bool poz(int a[10][10], int &i, int &j) {
    for(i = 1; i <= 9; i++)
        for(j = 1; j <= 9; j++)
            if(a[i][j] == 0)
                return 1;

    return 0;
}
bool rez(int a[10][10]) {
    int i, j;

    if(poz(a, i, j) == 0) {
        for(int i = 1; i <= 9; i++) {
            for(int j = 1; j <= 9; j++)
                fout << a[i][j] << ' ';

            fout << '\n';
        }

        exit(0);
    }

    for(int n = 1; n <= 9; n++) {
        if(verif(a, i, j, n) == 1) {
            a[i][j] = n;

            if(rez(a) == 1) {
                for(int i = 1; i <= 9; i++) {
                    for(int j = 1; j <= 9; j++)
                        fout << a[i][j] << ' ';

                    fout << '\n';
                }

                exit(0);
            }

            a[i][j] = 0;
        }
    }

    return 0;
}
