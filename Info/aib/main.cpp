#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "aib.in" );
ofstream fout( "aib.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, m;
int a[100005];
int aib[100005];
int lbs( int x )
{
    return ( x & ( -x ) );
}
void update( int pos, int x )
{
    for( int i = pos; i <= n; i += lbs( i ) )
        aib[i] += x;
}
int sum( int x )
{
    int s = 0;

    for( int i = x; i > 0; i -= lbs( i ) )
        s += aib[i];

    return s;
}
int caut_bin( int val )
{
    int l = 0, r = n + 1;

    while( r - l > 1 )
        {
            int mid = ( l + r ) / 2;
            int s = sum( mid );

            if( s == val )
                return mid;

            if( s > val )
                r = mid;
            else
                l = mid;
        }

    return -1;
}
int main()
{
    fast();
    fin >> n >> m;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a[i];
            update( i, a[i] );
        }

    while( m-- )
        {
            int t;
            fin >> t;

            if( t == 2 )
                {
                    int x;
                    fin >> x;
                    fout << caut_bin( x ) << '\n';
                    continue;
                }

            int a, b;
            fin >> a >> b;

            if( t == 0 )
                update( a, b );
            else
                fout << sum( b ) - sum( a - 1 ) << '\n';
        }

    return 0;
}
