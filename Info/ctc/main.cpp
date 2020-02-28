#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "ctc.in" );
ofstream fout( "ctc.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
vector<int>g[100005], sol[100005];
vector<int>gt[100005];
vector<int>ord;
int use[100005];
int m, n, nrctc;
void dfs( int x )
{
    use[x] = 1;

    for( auto it : g[x] )
        if( !use[it] )
            dfs( it );

    ord.pb( x );
}
void ctc( int x )
{
    sol[nrctc].pb( x );
    use[x] = 1;

    for( auto it : gt[x] )
        if( !use[it] )
            ctc( it );
}
int main()
{
    fast();
    fin >> n >> m;

    for( int i = 1; i <= m; i++ )
        {
            int x, y;
            fin >> x >> y;
            g[x].pb( y );
            gt[y].pb( x );
        }

    for( int i = 1; i <= n; i++ )
        if( !use[i] )
            dfs( i );

//    for( auto it : ord )
//        fout << it << ' ';
//
//    fout << endl;
    reverse( ord.begin(), ord.end() );

    for( int i = 1; i <= n; i++ )
        use[i] = 0;

    for( auto it : ord )
        if( !use[it] )
            {
                nrctc++;
                ctc( it );
            }

    fout << nrctc << '\n';

    for( int i = 1; i <= nrctc; i++ )
        {
            for( auto it : sol[i] )
                fout << it << ' ';

            fout << '\n';
        }

    return 0;
}
