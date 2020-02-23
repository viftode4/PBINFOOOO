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
int t;
int n, k, m;
int a[105];
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n >> m >> k;

            for( int i = 1; i <= n; i++ )
                cin >> a[i];

            for( int i = 1; i < n && m >= 0; i++ )
                {
                    m += a[i] - max( 0, ( a[i + 1] - k ) );
                }

            if( m < 0 )
                cout << "NO\n";
            else
                cout << "YES\n";
        }

    return 0;
}
