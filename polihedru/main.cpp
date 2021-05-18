#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define ll long long
#define pb push_back
#define mp make_pair
void fast()
{
    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 );
}
char a[1003][1003];
char mask[1003];
char cmask[1003];
int p, t, n, sol;
vector<int>poz;
vector < pair<char, pair<int, int> > >soll;
vector<int>c10, c11, l10, l11, c01, c00, l01, l00;
int main()
{
    fast();
    cin >> p >> t;

    while ( t-- )
        {
            cin >> n;

            for ( int i = 1; i <= n; i++ )
                for ( int j = 1; j <= n; j++ )
                    cin >> a[i][j];

            int ok = 1;

            for ( int i = 1; i <= n && ok; i++ )
                {
                    int c = 0;

                    for ( int j = 1; j <= n; j++ )
                        if ( a[i][j] == '1' )
                            c++;

                    if ( c != n / 2 )
                        {
                            ok = 0;
                            break;
                        }
                }

            for ( int j = 1; j <= n && ok; j++ )
                {
                    int c = 0;

                    for ( int i = 1; i <= n; i++ )
                        if ( a[i][j] == '1' )
                            c++;

                    if ( c != n / 2 )
                        {
                            ok = 0;
                            break;
                        }
                }

            for ( int i = 1; i <= n; i++ )
                {
                    mask[i] = a[1][i];

                    if ( mask[i] == '1' )
                        cmask[i] = '0';
                    else cmask[i] = '1';
                }

            int oa = 1, ob = 1;

            for ( int i = 1; i <= n; i++ )
                {
                    oa = ob = 1;

                    for ( int j = 1; j <= n; j++ )
                        if ( a[i][j] != mask[j] )
                            {
                                oa = 0;
                                break;
                            }

                    for ( int j = 1; j <= n; j++ )
                        if ( a[i][j] != cmask[j] )
                            {
                                ob = 0;
                                break;
                            }

                    if ( oa == 0 && ob == 0 )
                        break;
                }

            if ( p == 1 )
                {
                    if ( ok == 0 )
                        cout << 0 << '\n';
                    else if ( oa == 0 && ob == 0 )
                        cout << 0 << '\n';
                    else cout << 1 << '\n';
                }
            else if ( p == 2 )
                {
                    int ca = 0, cb = 0;
                    sol = 0;

                    for ( int i = 1; i <= n; i++ )
                        {
                            int x = a[1][i] - '0';

                            if ( x != i % 2 )
                                ca++;
                            else
                                cb++;
                        }

                    sol += min ( ca, cb ) / 2;
                    int ok = 0;
                    ca = cb = 0;

                    for ( int i = 1; i <= n; i++ )
                        {
                            int x = a[i][1] - '0';

                            if ( ok == 1 )
                                x = 1 - x;

                            if ( x != i % 2 )
                                ca++;
                            else
                                cb++;
                        }

                    sol += min ( ca, cb ) / 2;
                    cout << sol << '\n';
                }
            else
                {
                    soll.clear();
                    int ca = 0, cb = 0;
                    sol = 0;

                    for ( int i = 1; i <= n; i++ )
                        {
                            int x = a[1][i] - '0';

                            if ( x != i % 2 )
                                {
                                    ca++;

                                    if ( x == 1 )
                                        c11.pb ( i );
                                    else c10.pb ( i );
                                }
                            else
                                {
                                    cb++;

                                    if ( x == 1 )
                                        c01.pb ( i );
                                    else c00.pb ( i );
                                }
                        }

                    sol += min ( ca, cb ) / 2;
                    int ok = 0;

                    if ( cb < ca )
                        {
                            while ( !c01.empty() )
                                {
                                    soll.pb ( mp ( 'C', mp ( c01.back(), c00.back() ) ) );
                                    c01.pop_back();
                                    c00.pop_back();
                                }
                        }
                    else
                        {
                            while ( !c11.empty() )
                                {
                                    soll.pb ( mp ( 'C', mp ( c11.back(), c10.back() ) ) );
                                    c11.pop_back();
                                    c10.pop_back();
                                }
                        }

                    ca = cb = 0;

                    for ( int i = 1; i <= n; i++ )
                        {
                            int x = a[i][1] - '0';

                            if ( x != i % 2 )
                                {
                                    ca++;

                                    if ( x == 1 )
                                        l11.pb ( i );
                                    else l10.pb ( i );
                                }
                            else
                                {
                                    cb++;

                                    if ( x == 1 )
                                        l01.pb ( i );
                                    else l00.pb ( i );
                                }
                        }

                    if ( cb < ca )
                        {
                            while ( !l01.empty() )
                                {
                                    soll.pb ( mp ( 'L', mp ( l01.back(), l00.back() ) ) );
                                    l01.pop_back();
                                    l00.pop_back();
                                }
                        }
                    else
                        {
                            while ( !l11.empty() )
                                {
                                    soll.pb ( mp ( 'L', mp ( l11.back(), l10.back() ) ) );
                                    l11.pop_back();
                                    l10.pop_back();
                                }
                        }

                    //sol += min ( ca, cb ) / 2;
                    cout << soll.size() << '\n';

                    for ( auto it : soll )
                        cout << it.st << ' ' << min ( it.nd.st, it.nd.nd ) << ' ' << max ( it.nd.st, it.nd.nd ) << '\n';
                }
        }

    return 0;
}
