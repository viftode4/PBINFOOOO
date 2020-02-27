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
ll a[500005];
ll s[500005], p, u;
ll pre[500005];
ll suf[500005], maxi, pos;
ll sol[500005];
int main()
{
    fast();
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i] ;

    s[1] = 1;
    u = 1;
    pre[1] = a[1];

    for( int i = 2; i <= n; i++ )
        {
            u++;
            s[u] = i;

            while( a[s[u - 1]] > a[s[u]] )
                {
                    s[u - 1] = s[u];
                    u--;
                }

            pre[i] = pre[s[u - 1]] + ( s[u] - s[u - 1] ) * a[i];
        }

    reverse( a + 1, a + n + 1 );
    s[1] = 1;
    u = 1;
    suf[1] = a[1];

    for( int i = 2; i <= n; i++ )
        {
            u++;
            s[u] = i;

            while( a[s[u - 1]] > a[s[u]] )
                {
                    s[u - 1] = s[u];
                    u--;
                }

            suf[i] = suf[s[u - 1]] + ( s[u] - s[u - 1] ) * a[i];
        }

    reverse( a + 1, a + n + 1 );

    for( int i = 1; i <= n; i++ )
        if( maxi < suf[n - i + 1] + pre[i] )
            {
                maxi = suf[n - i + 1] + pre[i];
                pos = i;
            }

    sol[pos] = a[pos];
    int i = pos;

    for( int j = i + 1; j <= n; j++ )
        {
            if( a[j] >= sol[j - 1] )
                sol[j] = sol[j - 1];
            else
                sol[j] = a[j];
        }

    for( int j = i - 1; j >= 1; j-- )
        {
            if( a[j] >= sol[j + 1] )
                sol[j] = sol[j + 1];
            else
                sol[j] = a[j];
        }

    for( int i = 1; i <= n; i++ )
        cout << sol[i] << ' ';

    return 0;
}
