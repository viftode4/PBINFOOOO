#include <bits/stdc++.h>
using namespace std;
ifstream fin( "backforth.in" );
ofstream fout( "backforth.out" );
int a[12], b[12], n, m, x;
int da2[300], db2[300];
int A[300], B[300], s[3000];
int main()
{
    for( int i = 1; i <= 10; i++ )
        {
            cin >> x;
            int ok = 0, nr = 0;

            for( int j = 1; j <= n; j++ )
                if( x == a[j] && nr == 1 )
                    {
                        ok = 1;
                        break;
                    }
                else if( x == a[j] && nr < 1 )
                    nr++;

            if( ok == 0 )
                a[++n] = x;
        }

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= 10; i++ )
        {
            cin >> x;
            int ok = 0, nr = 0;

            for( int j = 1; j <= n; j++ )
                if( x == b[j] && nr == 1 )
                    {
                        ok = 1;
                        break;
                    }
                else if( x == b[j] && nr < 1 )
                    nr++;

            if( ok == 0 )
                b[++m] = x;
        }

    sort( b + 1, b + m + 1 );

    for( int i = 1; i <= n; i++ )
        cout << a[i] << ' ';

    cout << endl;

    for( int i = 1; i <= m; i++ )
        cout << b[i] << ' ';

    cout << endl;

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
                if( j == i )
                    continue;
                else
                    {
                        da2[a[i] + a[j]]++;
                        for(int )
                    }
        }

    for( int i = 1; i <= m; i++ )
        {
            for( int j = 1; j <= m; j++ )
                if( j == i )
                    continue;
                else
                    db2[b[i] + b[j]]++;
        }

    n = m = 0;

    for( int i = 0; i <= 200; i++ )
        {
            if( da2[i] != 0 )
                A[++n] = i;

            if( db2[i] != 0 )
                B[++m] = i;
        }

    for( int i = 1; i <= n; i++ )
        cout << A[i] << ' ';

    cout << endl;

    for( int i = 1; i <= m; i++ )
        cout << B[i] << ' ';

    cout << endl;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            s[1000 + B[j] - A[i]]++;

    int nr = 0;

    for( int i = 1; i <= 2000; i++ )
        if( s[i] != 0 )
            {
                cout << i << ' ';
                nr++;
            }

    cout << nr;
    return 0;
}
