#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, m, k;
vector<char>sol;
int main()
{
    fast();
    cin >> n >> m >> k;

    for( int i = 1; i <= k; i++ )
        {
            int x, y;
            cin >> x >> y;
        }

    for( int i = 1; i <= k; i++ )
        {
            int x, y;
            cin >> x >> y;
        }

    int x = n, y = m;

    while( x != 1 )
        {
            x--;
            sol.pb( 'U' );
        }

    while( y != 1 )
        {
            y--;
            sol.pb( 'L' );
        }

    while( 1 )
        {
            while( x != n )
                {
                    x++;
                    sol.pb( 'D' );
                }

            if( y == m )
                break;

            y++;
            sol.pb( 'R' );

            while( x != 1 )
                {
                    x--;
                    sol.pb( 'U' );
                }

            if( y == m )
                break;

            y++;
            sol.pb( 'R' );
        }


    if( sol.size() > 2 * n * m )
        {
            cout << -1;
            return 0;
        }

    cout << sol.size() << '\n';;

    for( auto it : sol )
        cout << it;

    return 0;
}
