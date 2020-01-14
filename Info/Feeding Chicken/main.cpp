#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define nd second
#define st first
int t;
int n, m, k;
char a[110][110];
char s[110][110];
vector<char>v;
int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> t;

    for( int i = 0; i < 26; i++ )
        v.pb( i + 'a' );

    for( int i = 0; i < 26; i++ )
        v.pb( i + 'A' );

    for( int i = 0; i <= 9; i++ )
        v.pb( i + '0' );

    while( t-- )
        {
            cin >> n >> m >> k;
            int nr = 0;

            for( int i = 1; i <= n; i++ )
                for( int j = 1; j <= m; j++ )
                    {
                        cin >> a[i][j];

                        if( a[i][j] == 'R' )
                            nr++;
                    }

            vector<int>val;
            int r = nr % k;
            int c =  k;

            //cout << nr << ' ';
            while( c )
                {
                    if( c > r )
                        val.push_back( nr / k );
                    else
                        val.push_back( nr / k + 1 );

                    c--;
                }

//            for( auto it : val )
//                cout << it << ' ';
//
//            cout << '\n';
            int cur = 0, p = 0;;

            for( int i = 1; i <= n; i++ )
                {
                    if( i % 2 == 1 )
                        {
                            for( int j = 1; j <= m; j++ )
                                {
                                    if( p >= k )
                                        p = k-1;

                                    s[i][j] = v[p];

                                    if( a[i][j] == 'R' )
                                        cur++;

                                    if( cur == val[p] )
                                        {
                                            p++;
                                            cur = 0;
                                        }
                                }
                        }
                    else
                        {
                            for( int j = m; j >= 1; j-- )
                                {
                                    if( p >= k )
                                        p = k-1;

                                    s[i][j] = v[p];

                                    if( a[i][j] == 'R' )
                                        cur++;

                                    if( cur == val[p] )
                                        {
                                            p++;
                                            cur = 0;

                                        }
                                }
                        }
                }

            for( int i = 1; i <= n; i++ )
                {
                    for( int j = 1; j <= m; j++ )
                        cout << s[i][j];

                    cout << '\n';
                }
        }

    return 0;
}
