#include <bits/stdc++.h>
#define nd second
#define st first
#define mp make_pair
#define pb push_back
using namespace std;
int n,  ok1, ok2;
vector < pair<int, int> >v;
vector<int>a00, a01, a10, a11;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            int x, y;
            cin >> x >> y;
            v.pb( mp( x + 1e6, y + 1e6 ) );

            if( ( x + y ) % 2 == 1 )
                ok1 = 1;
            else
                ok2 = 1;

            if( x % 2 == 1 && y % 2 == 1 )
                a11.pb( i - 1 );
            else if( x % 2 == 0 && y % 2 == 1 )
                a01.pb( i - 1 );
            else if( x % 2 == 0 && y % 2 == 0 )
                a00.pb( i - 1 );
            else if( x % 2 == 1 && y % 2 == 0 )
                a10.pb( i - 1 );
        }

    while( 1 )
        {
            int lx = -1, ly = -1, dif = 0;

            for( auto it : v )
                {
                    int x, y;
                    x = it.st;
                    y = it.nd;

                    if( ( x + y ) % 2 == 1 )
                        ok1 = 1;
                    else
                        ok2 = 1;

                    if( lx != -1 )
                        {
                            if( lx % 2 != x % 2 || ly % 2 != y % 2 )
                                dif = 1;
                        }

                    lx = x;
                    ly = y;
                }

            if( dif == 0 )
                {
                    for( int i = 0; i < n; i++ )
                        v[i].st /= 2, v[i].nd /= 2;

                    continue;

                }

            if( ok1 && !ok2 )
                {
                    cout << a01.size() << '\n';

                    for( auto it : a01 )
                        cout << it + 1 << ' ';

                    return 0;
                }

            if( !ok1 && ok2 )
                {
                    cout << a00.size() << '\n';

                    for( auto it : a00 )
                        cout << it + 1 << ' ';

                    return 0;
                }

            if( ok1 && ok2 )
                {
                    cout << a00.size() + a01.size() << '\n';

                    for( auto it : a00 )
                        cout << it + 1 << ' ';

                    for( auto it : a01 )
                        cout << it + 1 << ' ';

                    return 0;
                }
        }


    return 0;
}
