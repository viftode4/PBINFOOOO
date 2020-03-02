#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "cuplaj.in" );
ofstream fout( "cuplaj.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int pix[10005];
int piy[10005];
int use[10005];
vector<int>ga[10005], gb[10005];
int x, y;
int n, m, k;
int dfs( int x )
{
    use[x] = 1;

    for( auto it : ga[x] )
        if( !piy[it] || ( !use[piy[it]] && dfs( piy[it] ) ) )
            {
                piy[it] = x;
                pix[x] = it;
                return 1;
            }

    return 0;
}
int main()
{
    fast();
    fin >> n >> m >> k;

    for( int i = 1; i <= k; i++ )
        {
            fin >> x >> y;
            ga[x].pb( y );
            gb[y].pb( x );
        }

    int ok = 1, ans = 0;

    while( ok )
        {
            ok = 0;

            for( int i = 1; i <= max( n, m ); i++ )
                use[i] = 0;

            for( int i = 1; i <= n; i++ )
                if( !use[i] && !pix[i] )
                    {
                        ok += dfs( i );
                    }

            ans += ok;
        }

    fout << ans << '\n';

    for( int i = 1; i <= n; i++ )
        if( pix[i] )
            fout << i << ' ' << pix[i] << '\n';

    return 0;
}
