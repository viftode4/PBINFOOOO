#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, c, k, sola, solb, solr = INT_MAX;
int a[100005];
int ca[100005];
int xa[100005];
int poz[100005];
int main()
{
    cin >> c >> n >> k;

    for ( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            xa[i] = a[i];
        }

    if ( c == 2 )
        {
            for ( int k = 1; k <= n; k++ )
                {
                    solr = INT_MAX;

                    for ( int x = 1; x <= n; x++ )
                        {
                            int nr = 0, ok;

                            for ( int i = 1; i <= n; i++ )
                                ca[i] = xa[i];

                            if ( x < k )
                                {
                                    for ( int i = x; i < k; i++ )
                                        {
                                            swap ( ca[i], ca[i + 1] );
                                            nr++;
                                        }
                                }
                            else
                                for ( int i = x; i > k; i-- )
                                    {
                                        swap ( ca[i], ca[i - 1] );
                                        nr++;
                                    }

                            sola = solb = 0;

                            for ( int i = 1; i <= n; i++ )
                                a[i] = ca[i];

                            //sola
                            do
                                {
                                    ok = 0;

                                    for ( int i = 1; i < k; i++ )
                                        if ( a[i] < a[i + 1] )
                                            {
                                                swap ( a[i], a[i + 1] );
                                                sola++;
                                                ok = 1;
                                            }
                                }
                            while ( ok );

                            do
                                {
                                    ok = 0;

                                    for ( int i = k; i < n; i++ )
                                        if ( a[i] > a[i + 1] )
                                            {
                                                swap ( a[i], a[i + 1] );
                                                sola++;
                                                ok = 1;
                                            }
                                }
                            while ( ok );

                            //solb
                            for ( int i = 1; i <= n; i++ )
                                a[i] = ca[i];

                            do
                                {
                                    ok = 0;

                                    for ( int i = k; i < n; i++ )
                                        if ( a[i] > a[i + 1] )
                                            {
                                                swap ( a[i], a[i + 1] );
                                                solb++;
                                                ok = 1;
                                            }
                                }
                            while ( ok );

                            do
                                {
                                    ok = 0;

                                    for ( int i = 1; i < k; i++ )
                                        if ( a[i] < a[i + 1] )
                                            {
                                                swap ( a[i], a[i + 1] );
                                                solb++;
                                                ok = 1;
                                            }
                                }
                            while ( ok );

                            solr = min ( solr, min ( sola, solb ) + nr );
                        }

                    cout << solr << ' ';
                }
        }

    return 0;
}
