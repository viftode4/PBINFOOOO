#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "patrate2.in" );
ofstream fout( "patrate2.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
struct huge
{
    int n = 0;
    int a[10006] = {0};
};
huge operator+( huge a, huge b )
{
    int n = a.n;
    int m = b.n;
    int siz = max( n, m );
    huge c;
    c.n = siz;
    int t = 0;

    for( int i = 1; i <= siz; i++ )
        {
            c.a[i] = a.a[i] + b.a[i] + t;
            t = c.a[i] / 10;
            c.a[i] %= 10;
        }

    if( t )
        {
            siz++;
            c.a[siz] = 1;
            c.n = siz;
        }

    return c;
}
huge operator*( huge a, ll b )
{
    huge s;
    int n = a.n, t = 0;

    for( int i = 1; i <= n; i++ )
        {
            s.a[i] = a.a[i] * b + ( t % 10 );
            t /= 10;
            t += s.a[i] / 10;
            s.a[i] %= 10;
        }

    while( t )
        {
            n++;
            s.a[n] = t % 10;
            t /= 10;
        }

    s.n = n;
    return s;
}
ll n;
huge dp[10010][2];
int main()
{
    fast();
    fin >> n;
    dp[1][0].a[1] = 1;
    dp[1][1].a[1] = 1;
    dp[1][0].n = 1;
    dp[1][1].n = 1;

    for( int i = 2; i <= n; i++ )
        {
            dp[i][0] = dp[i - 1][0] * 4LL + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1] + dp[i - 1][0] * 2LL;
        }

    for( int i = dp[n][0].n; i > 0; i-- )
        fout << dp[n][0].a[i]<<'\n';

    return 0;
}
