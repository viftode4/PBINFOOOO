#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "deleg.in" );
ofstream fout( "deleg.out" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n;
int use[100005];
int grad[100005];
int sol[100005];
vector<int>g[100005];
vector<int>frunze;
int main()
{
    fast();
    fin >> n;

    for( int i = 1; i < n; i++ )
        {
            int x, y;
            fin >> x >> y;
            g[x].pb( y );
            g[y].pb( x );
            grad[x]++;
            grad[y]++;
        }

    for( int i = 1; i <= n; i++ )
        if( grad[i] == 1 )
            frunze.pb( i );

    queue<int>q;

    for( auto it : frunze )
        {
            q.push( it );
            use[it] = 1;
        }

    while( !q.empty() )
        {
            int x = q.front();
            q.pop();

            for( auto it : g[x] )
                if( !use[it] )
                    {
                        use[it] = use[x] + 1;
                        q.push( it );
                    }
        }

    for( int i = 1; i <= n; i++ )
        sol[use[i]] = 1;

    for( int i = 1; i <= n - 1; i++ )
        fout << sol[i];

    return 0;
}
