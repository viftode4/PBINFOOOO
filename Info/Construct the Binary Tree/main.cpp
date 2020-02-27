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
int t;
int n, d;
int p[5010], c[5010];
void afisare( vector<int>niv[], int nivel )
{

    for( int i = 1; i <= nivel; i++ )
        {
            for( auto x : niv[i] )
                {
                    for( auto it : niv[i - 1] )
                        if( c[it] < 2 )
                            {
                                p[x] = it;
                                c[it]++;
                                break;
                            }
                }
        }

    for( int i = 2; i <= n; i++ )
        cout << p[i] << ' ';

    cout << '\n';
}
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n >> d;
            int s = 0;

            for( int i = 1; i <= n; i++ )
                p[i] = c[i] = 0;

            vector<int>niv[n + 2];
            vector<int>g[n + 2];
            int last = 2, nivel = 1;
            niv[0].pb( 1 );

            while( last <= n )
                {

                    if( niv[nivel].size() == ( 1 << nivel ) )
                        nivel++;

                    if( niv[nivel].size() < ( 1 << nivel ) )
                        {
                            s += nivel;
                            niv[nivel].pb( last );
                            last++;
                        }
                }

            if( s > d )
                {
                    cout << "NO\n";
                    continue;
                }
            else if( s == d )
                {
                    cout << "YES\n";
                    afisare( niv, nivel );
                    continue;
                }
            else
                {
                    while( s < d )
                        {
                            for( int i = 1; i <= nivel; i++ )
                                {
                                    int x = niv[i].size();
                                    int y = niv[i + 1].size();

                                    if( y == ( 1 << i + 1 ) )
                                        continue;

                                    if( ( x - 1 ) * 2 < y + 1 )
                                        continue;

                                    niv[i + 1].pb( niv[i].back() );
                                    niv[i].pop_back();
                                    s++;
                                }

                            if( !niv[nivel + 1].empty() )
                                nivel++;
                        }

                    cout << "YES\n";
                    afisare( niv, nivel );
                }

        }

    return 0;
}
