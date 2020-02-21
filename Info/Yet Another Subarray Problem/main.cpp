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
ll n, m, k;
ll sp[300005];
ll a[300005];
ll best[300005];
int main()
{
    fast();
    cin >> n >> m >> k;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            sp[i] = sp[i - 1] + a[i];
        }

    for( int i = 1; i <= n; i++ )
        for( int j = i - 1; j >= max( 0LL, i - m ); j-- )
            best[i] = max( best[i], best[j] + sp[i] - sp[j] - k );

    ll sol = 0;

    for( int i = 1; i <= n; i++ )
        sol = max( sol, best[i] );

    cout << sol;
    return 0;
}
