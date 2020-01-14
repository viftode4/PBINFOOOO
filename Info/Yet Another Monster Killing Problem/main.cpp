#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define mp make_pair
#define pb push_back
int t;
int n, m;
int a[200005], dp[200005];
int w[200005];
vector<pair<int, int>>v;
set<int>::iterator it;
int cond( pair<int, int> a, pair<int, int>b )
{
    if( a.nd == b.nd )
        {
            return a.st > b.st;
        }
    else
        return a.nd > b.nd;
}
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> t;

    while( t-- )
        {
            cin >> n;
            //s.clear();
            v.clear();

            for( int i = 1; i <= n; i++ )
                cin >> a[i];

            cin >> m;

            //map<int, vector<int>>f;
            for( int i = 1; i <= m; i++ )
                {
                    int x, y;
                    cin >> x >> y;
                    w[y] = max( w[y], x );
                    //it = s.lower_bound( x );
                    //cout << *it << ' ';
//                    for( it; it != s.end() ; it++ )
//                        {
//                            int k = *it;
//                            //cout << k << ' ';
//                            f[k].push_back( i );
//                        }
                }

            for( int i = 1; i <= n; i++ )
                if( w[i] )
                    {
                        v.pb( mp( w[i], i ) );
                    }

            sort( v.begin(), v.end(), cond );

            for( int i = 0; i < m; i++ )
                cout << v[i].st << ' ' << v[i].nd << '\n';

            /*
                        int i = 0, ok = 1;

                        while( i < n || ok )
                            {
                                ok = 0;
                                int lg = 0;

                                for( int i = 0; i < m; i++ )
                                    {
                                        int k;

                                        for( k = i + 1; k <= i + v[i].nd; k++ )
                                            if( a[i] > v[i].st )
                                                break;

                                        lg = max( lg, k );
                                    }
                            }
                    }
                    */
        }

    return 0;
}
