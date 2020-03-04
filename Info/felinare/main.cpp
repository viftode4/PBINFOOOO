#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "felinare.in" );
ofstream fout( "felinare.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int l[10005];
int r[10005];
int use[10005];
vector<int>ga[10005], gb[10005];
int x, y;
int n, m, k;
int culpaj( int x )
{
    use[x] = 1;

    for( auto it : ga[x] )
        if( !r[it] || ( !use[r[it]] && culpaj( r[it] ) ) )
            {
                r[it] = x;
                l[x] = it;
                return 1;
            }

    return 0;
}
int main()
{
    fast();
    fin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            fin >> x >> y;
            ga[x].pb( y );
            gb[y].pb( x );
        }

    int ok = 1, ans = 0;

    while( ok )
        {
            ok = 0;

            for( int i = 1; i <= n; i++ )
                use[i] = 0;

            for( int i = 1; i <= n; i++ )
                if( !use[i] && !l[i] )
                    ok += culpaj( i );

            ans += ok;
        }

    fout << ans << '\n';

    for( int i = 1; i <= n; i++ )
        if( l[i] )
            fout << i << ' ' << l[i] << '\n';

    return 0;
}
