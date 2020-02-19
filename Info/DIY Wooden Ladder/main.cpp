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
int n, t;
int a[100005];
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n;

            for( int i = 1; i <= n; i++ )
                cin >> a[i];

            sort( a + 1, a + n + 1 );
            int x = min( a[n], a[n - 1] );
            cout << min( x - 1, n - 2 ) << '\n';
        }

    return 0;
}
