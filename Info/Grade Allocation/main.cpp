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
int t, n, k;
int a[10005];
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n >> k;
            int s=0;
            for( int i = 1; i <= n; i++ )
                {
                    cin >> a[i];
                    s += a[i];
                }

            cout << min( s, k ) << '\n';
        }

    return 0;
}
