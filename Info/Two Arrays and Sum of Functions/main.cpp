#include <bits/stdc++.h>
using namespace std;
int n;
const unsigned long long MOD = 998244353;
struct nr
{
    unsigned long long v;
    int i;
} a[200005], b[200005];
unsigned long long sola[200005], solb[200005];
int cond1( nr a, nr b )
{
    return a.v < b.v;
}
int cond2( nr a, nr b )
{
    return a.v > b.v;
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i].v;
            sola[i] = a[i].v;
            a[i].i = i;
        }

    for( int i = 1; i <= n; i++ )
        {
            cin >> b[i].v;
            b[i].i = i;
        }

    sort( a + 1, a + n + 1, cond1 );
    sort( b + 1, b + n + 1, cond2 );

    for( int i = 1; i <= n; i++ )
        solb[a[i].i] = b[i].v;

    unsigned long long p = 0;

    for( int i = 1; i <= n; i++ )
        p = ( p + ( ( sola[i] * solb[i] ) % MOD * ( i * ( n - i + 1 ) ) % MOD ) % MOD ) % MOD;


    cout << p ;
    return 0;
}
