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

int n;
int a[300005];
int b[300005];
int main()
{
    fast();
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            dp[i] = max( dp[i - 1], a[i] );
        }

    for( int i = 1; i <= n; i++ )
        cin >> b[i];

    for( int i = 1; i <= n; i++ )
        s.insert( i );

    cout << *s.begin() << ' ';

    for( int i = 1; i <= n - 1; i++ )
        {
            s.erase( s.find( a[b[i]] ) );
            cout << *s.begin() << ' ';
        }

    return 0;
}
