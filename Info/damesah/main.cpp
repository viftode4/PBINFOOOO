#include <bits/stdc++.h>
using namespace std;
ifstream fin( "damesah.in" );
ofstream fout( "damesah.out" );
const int N = 50;
int a[30], col[30], dp[200], ds[200];
long long ok;
int n;
void afisare()
{
    for( int i = 1; i <= n; i++ )
        fout << a[i] << ' ';

    fout << endl;
}
void generare( int k )
{
    if( k > n )
        {
            ok++;

            if( ok == 1 )
                {
                    afisare();
                }
        }

    for( int i = 1; i <= n; i++ )
        if( col[i] == 0 && ds[k + i] == 0 && dp[k - i + N] == 0 )
            {
                a[k] = i;
                col[i] = 1;
                ds[k + i] = 1;
                dp[k - i + N] = 1;
                generare( k + 1 );
                col[i] = 0;
                ds[k + i] = 0;
                dp[k - i + N] = 0;
            }
}
int main()
{
    fin >> n;
    generare( 1 );
    fout << ok;
}
