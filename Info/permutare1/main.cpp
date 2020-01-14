#include <bits/stdc++.h>
using namespace std;
ifstream fin( "permutare1.in" );
ofstream fout( "permutare1.out" );
int n, m, a[100005];
long long x, s;
long long cost( int i )
{
    long long cc = 0;

    for( int j = 1; j <= m; j++ )
        if( i < j )
            cc += min( j - i, n - j + i );
        else
            cc += min( i - j, j + n - i );

    return cc;
}
int main()
{
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        fin >> x;

    for( int i = 1; i <= m; i++ )
        {
            fin >> x;

            if( x > n / 2 )
                s += n - x;
            else
                s += x;
        }

    for( int i = 2; i <= n; i++ )
        {
            x = min( x, cost( i ) );
        }

    fout << x;
    return 0;
}
