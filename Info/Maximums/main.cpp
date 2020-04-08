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
ll n;
ll a[200005];
ll sol[200005];
ll x[200005];
int main()
{
    fast();
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sol[1] = a[1];
    x[1] = 0LL;
    x[2] = a[1];

    for( int i = 2; i <= n; i++ )
        {
            sol[i] = x[i] + a[i];
            x[i + 1] = max( x[i], sol[i] );
        }

    for( int i = 1; i <= n; i++ )
        cout << sol[i] << ' ';

    return 0;
}
