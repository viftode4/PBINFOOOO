#include <bits/stdc++.h>
using namespace std;
ifstream fin( "blist.in" );
ofstream fout( "blist.out" );
long long n, nr;
int m;
int x, y, k;
long long a[2001];
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> x >> y >> k;
            m = max( m, y );
            a[x] += k;
            a[y + 1] -= k;
        }

    for( int i = 1; i <= m; i++ )
        {
            a[i] += a[i - 1];
            nr = max( nr, a[i] );
        }

    fout << nr;
    return 0;
}
