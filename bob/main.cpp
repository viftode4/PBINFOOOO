#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define ll long long
#define mp make_pair
#define MOD 1000000007
void fast()
{
    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 );
}
ll t;
ll n, p, k;
ll sol;
vector<ll>g[22];
vector<pair<ll, ll>>inter;
vector<pair<ll, ll>>si;
char a[200010][22], mask[212];
int main()
{
    fast();
    cin >> p;
    cin >> t;

    while ( t-- )
        {
            cin >> n >> k;
            sol = 0;
            int l = 1, r = 0;
            inter.clear();

            for ( int i = 1; i <= n; i++ )
                {
                    for ( int j = 1; j <= k; j++ )
                        {
                            cin >> a[i][j];

                            if ( a[i][j] == '1' )
                                {
                                    mask[j] = 1;
                                    r = i;
                                }
                        }

                    int ok = 1;

                    for ( int x = 1; x <= k; x++ )
                        {
                            if ( mask[x] == 0 )
                                {
                                    ok = 0;
                                    break;
                                }
                        }

                    if ( ok )
                        {
                            sol++;
                            l = i;

                            for ( int x = 1; x <= k; x++ )
                                {
                                    for ( int j = i; j >= 1; j-- )
                                        if ( a[j][x] == '1' )
                                            {
                                                l = min ( l, j );
                                                break;
                                            }
                                }

                            inter.pb ( mp ( l, r ) );

                            for ( int x = 1; x <= k; x++ )
                                mask[x] = 0;

                            l = i + 1;
                        }
                }

            if ( p == 1 )
                cout << sol << '\n';
            else
                {
                    int x = inter.size();
                    sol = 1;

                    for ( int i = 0; i < x - 1; i++ )
                        sol = ( sol * ( inter[i + 1].st - inter[i].nd ) % MOD ) % MOD;

                    cout << sol << '\n';
                }
        }

    return 0;
}

