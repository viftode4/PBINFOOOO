#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define st first
#define nd second
int t, n, v, k, nr, start;
char x[2005];
string a;
vector<int>in, fi;
vector<pair<int, int>>sol;
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> t;
    //t = 1;

    while( t-- )
        {
            cin >> n >> k;
            cin >> a;
            v = 0;
            nr = 0;
            sol.clear();

            for( int i = 0; a[i]; i++ )
                {
                    if( a[i] == '(' )
                        in.pb( i );
                    else
                        fi.pb( i );
                }

            int i = 0;

            for( i = 0; i < n; i++ )
                {
                    if( a[i] != '(' )
                        {
                            for( int j = i + 1; j < n; j++ )
                                {
                                    if( a[j] == '(' )
                                        {
                                            nr++;
                                            sol.pb( mp( i, j ) );
                                            reverse( a.begin() + i, a.begin() + j + 1 );
                                            break;
                                        }
                                }
                        }

                    if( a[i] == '(' && a[i + 1] != ')' )
                        {
                            for( int j = i + 1; j < n; j++ )
                                {
                                    if( a[j] == ')' )
                                        {
                                            nr++;
                                            sol.pb( mp( i + 1, j ) );
                                            reverse( a.begin() + i + 1, a.begin() + j + 1 );
                                            break;
                                        }
                                }

                            k--;
                            i++;

                        }
                    else if( a[i] == '(' && a[i + 1] == ')' )
                        {
                            i++, k--;
                        }

                    if( k == 0 )
                        {
                            start = i;
                        }
                }

            if( n != 2 )
                sol.pb( mp( min( start, n - 2 ), max( start, n - 2 ) ) );

            cout << sol.size() << '\n';

            for( auto it : sol )
                cout << it.st + 1 << ' ' << it.nd + 1 << '\n';

        }


    return 0;
}
