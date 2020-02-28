#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "ssm.in" );
ofstream fout( "ssm.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll n, s, d, smax = -1e9;
ll a[6000005];
void var1()
{
    ll smin = 0, j = 1, sp = 0;

    for( int i = 1 ; i <= n; i++ )
        {
            sp = sp + a[i];
            ll sum = sp - smin;

            if( sum > smax )
                {
                    smax = sum;
                    s = j;
                    d = i;
                }

            if( sp < smin )
                {
                    smin = sp;
                    j = i + 1;
                }
        }
}
void var2()
{
    int j = 1, dp = 0;

    for( int i = 1; i <= n; i++ )
        {
            if( dp < 0 )
                j = i;

            dp = max( dp + a[i], a[i] );

            if( smax < dp )
                {
                    smax = dp;
                    s = j;
                    d = i;
                }
        }
}
int main()
{
    fast();
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> a[i];

///varianta 1
    var1();
///varianta 2
    // var2();

    fout << smax << ' ' << s << ' ' << d;
    return 0;
}
