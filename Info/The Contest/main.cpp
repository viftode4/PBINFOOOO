#include <bits/stdc++.h>
using namespace std;
int n1, n2, n3;
set<int>a1, a2;
set<int, greater<int>>a3;
int sol, x, nr1, nr3;
int cost[]
int main()
{
    cin >> n1 >> n2 >> n3;
    sol = min( {n1 + n2, n1 + n3, n2 + n3} );

    for( int i = 1; i <= n1; i++ )
        {
            cin >> x;
            a1.insert( x );
        }

    for( int i = 1; i <= n2; i++ )
        {
            cin >> x;
            a2.insert( x );
        }

    for( int i = 1; i <= n3; i++ )
        {
            cin >> x;
            a3.insert( x );
        }

    int n = n1 + n2 + n3;
    int ant = 0, ok = 0;

    for( auto it : a1 )
        {
            if( it - 1 != ant )
                {
                    ok = 1;
                }

            ant--;

            if( ok )
                nr1 ++;
        }

    ok = 0;
    ant = n + 1;

    for( auto it : a3 )
        {
            if( it + 1 != ant )
                {
                    ok = 1;
                }

            ant--;

            if( ok )
                nr3 ++;
        }
    for(int i=1;i<=n;i++)
    {

    }
    sol = min( sol, nr1 + nr3 );
    cout << nr1 << ' ' << nr3;
    return 0;
}
