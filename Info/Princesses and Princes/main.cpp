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
int t, n;
vector<int>g[100005], afara;
int use[100005];
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> n;
            afara.clear();

            for( int i = 1; i <= n; i++ )
                {
                    use[i] = 0;
                    g[i].clear();
                    int y;
                    cin >> y;

                    for( int j = 1; j <= y; j++ )
                        {
                            int x;
                            cin >> x;
                            g[i].pb( x );
                        }
                }

            for( int i = 1; i <= n; i++ )
                {
                    int ok = 0;

                    for( auto it : g[i] )
                        if( !use[it] )
                            {
                                use[it] = 1;
                                ok = 1;
                                break;
                            }

                    if( !ok )
                        afara.pb( i );
                }

            if( afara.empty() )
                {
                    cout << "OPTIMAL\n";
                    continue;
                }

            cout << "IMPROVE\n";

            for( int i = 1; i <= n; i++ )
                if( !use[i] )
                    {
                        int x = afara.back();
                        afara.pop_back ();
                        cout << x << ' ' << i << '\n';
                        break;
                    }

        }

    return 0;
}
