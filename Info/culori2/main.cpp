#include <bits/stdc++.h>
using namespace std;
ifstream fin( "culori2.in" );
ofstream fout( "culori2.out" );
int n;
unsigned long long a[5010][6], x;
int main()
{
    fin >> n;
    a[1][1] = a[1][2] = a[1][3] = a[1][4] = a[1][5] = 1;

    //1 alb
    //2 albastru
    //3 rosu
    //4 verde
    //5 galben
    for( int i = 2; i <= n; i++ )
        {
            a[i][2] += a[i - 1][1];
            a[i][1] += a[i - 1][2];
            a[i][3] += a[i - 1][2];
            a[i][2] += a[i - 1][3];
            a[i][4] += a[i - 1][3];
            a[i][3] += a[i - 1][4];
            a[i][5] += a[i - 1][4];
            a[i][4] += a[i - 1][5];
        }

    x = a[n][1] + a[n][2] + a[n][3] + a[n][5] + a[n][4];
    fout << x;
    return 0;
}
