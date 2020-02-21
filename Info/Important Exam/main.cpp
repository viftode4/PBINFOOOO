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
int n, m, sol;;
int a[10005];
string s[1005];
int main()
{
    fast();
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> s[i];


    for( int i = 1; i <= m; i++ )
        {
            cin >> a[i];
            int x = 0, xmax = 0;

            for( char c = 'A'; c <= 'E'; c++ )
                {
                    x = 0;

                    for( int j = 1; j <= n; j++ )
                        if( s[j][i - 1] == c )
                            x++;

                    xmax = max( xmax, x );
                }

            sol += a[i] * xmax;
        }

    cout << sol;
    return 0;
}
