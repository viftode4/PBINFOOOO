#include <bits/stdc++.h>
#define st first
#define nd second
#define INF 1e15
#define pb push_back
#define ll long long
using namespace std;
vector< pair < ll, pair<ll, ll> > > muchii;
map<ll, ll> normalizare;
ll rf[805][805], cnt;
ll care[805];
ll n, m, k;
int main()
{
    cin >> n >> m >> k;

    for( int i = 1; i <= m; i++ )
        {
            int x, y, z;
            cin >> x >> y >> z;
            muchii.pb( {z, {x, y}} );
        }

    cnt = 0;
    sort( muchii.begin(), muchii.end() );

    for( int i = 1; i <= 800; i++ )
        for( int j = 1; j <= 800; j++ )
            {
                rf[i][j] = INF;

                if( i == j )
                    rf[i][j] = 0;
            }

    for( int i = 0; i < min( k, m ); i++ )
        {
            ll x, y, w;
            x = muchii[i].nd.st;
            y = muchii[i].nd.nd;
            w = muchii[i].st;

            if( !normalizare[x] )
                {
                    cnt++;
                    normalizare[x] = cnt;
                    care[cnt] = x;
                }

            if( !normalizare[y] )
                {
                    cnt++;
                    normalizare[y] = cnt;
                    care[cnt] = y;
                }

            rf[normalizare[x]][normalizare[y]] = rf[normalizare[y]][normalizare[x]] = min( rf[normalizare[x]][normalizare[y]], w );
        }

    for( int x = 1; x <= cnt; x++ )
        for( int i = 1; i <= cnt; i++ )
            for( int j = 1; j <= cnt; j++ )
                rf[i][j] = min( rf[i][j], rf[i][x] + rf[x][j] );

    vector<ll>ans;
//
//    for( int i = 1; i <= cnt; i++ )
//        {
//            for( int j = 1; j <= cnt; j++ )
//                cout << rf[i][j] << ' ';
//
//            cout << endl;
//        }

    for( int i = 1; i <= cnt; i++ )
        for( int j = 1; j <= cnt; j++ )
            if( i != j && j <= i )
                ans.pb( rf[i][j] );

    sort( ans.begin(), ans.end() );
    cout << ans[k - 1];
    return 0;
}
