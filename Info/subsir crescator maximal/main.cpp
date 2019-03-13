#include <bits/stdc++.h>
using namespace std;
ifstream fin( "scmax.in" );
ofstream fout( "scmax.out" );
int n, a[100005], r[100005], sm, k = 1, dp[100005];
vector<int> sol;
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a[i];
            r[i] = INT_MAX;
        }

    r[1] = a[1];
    int v = 1;
    dp[1] = 1;

    //fout << "REZ:" << 1 << ' ' << r[1] << endl;
    for( int i = 2; i <= n; i++ )
        {
            // cout<<"V: "<<v<<' ';
            int s = 0, d = v + 1;

            while( s != d )
                {
                    int m = ( s + d + 1 ) / 2;

                    if( a[i] > r[m] )
                        s = m;
                    else
                        d = m - 1;
                }

            dp[i] = s + 1;
            // cout << "s : " << s<< endl;
            v = max( s + 1, v );
            r[s + 1] = a[i];
            // cout << "REZ:"<<endl;
            //     for( int i = 1; i <= v; i++ )
            //         cout << i << ' ' << r[i] << '\n';
            // cout << "Nr: " << a[i] << endl;
        }

    fout << v << endl;
    int p = v, el = 0;

    for( int i = n; i >= 1 && p > 0; i-- )
        {
            if( p == dp[i] )
                {
                    if( el == 0 )
                        el = a[i];

                    if( el >= a[i] )
                        {
                            sol.push_back( a[i] );
                            p--;
                        }
                }
        }
        sort( sol.begin(), sol.end() );

        for( auto it:sol )
            fout << it << ' ';

    return 0;
}
