#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "antivirus.in" );
ofstream fout ( "antivirus.out" );
int n, t, k;
int a[2020];
int sp[2020];
int best[2020][2020];
int dp[2020][2020];
int main()
{
    fin >> t;

    while ( t )
        {
            t--;
            fin >> n >> k;
            int cant = n - k;

            for ( int i = 0; i <= 2012; i++ )
                for ( int j = 0; j <= 2012; j++ )
                    best[i][j] = dp[i][j] = 0;

            vector<int>v[2020];
            int t = 1;
            long long s = 0;

            for ( int i = 1; i <= n; i++ )
                {
                    fin >> a[i];
                    s += a[i];

                    if ( a[i] != 0 )
                        v[t].push_back ( a[i] );
                    else if ( v[t].size() != 0 )
                        t++;
                }
            if(a[n]==0)
                t--;
            // int crt = 1;

            for ( int x = 1; x <= t; x++ )
                {
                    if ( x == t && a[n] != 0 )
                        {
                            best[x][1] = v[x][v[x].size() - 1];

                            for ( int i = v[x].size() - 2; i >= 0; i-- )
                                best[x][v[x].size() - i] = best[x][v[x].size() - i - 1] + v[x][i];

                            continue;
                        }
                    else if ( x == 1 && a[1] != 0 )
                        {
                            best[x][1] = v[x][0];

                            for ( int i = 1; i < v[x].size(); i++ )
                                best[x][i + 1] = best[x][i] + v[x][i];

                            continue;
                        }

                    sp[0] = v[x][0];

                    for ( int i = 1; i < v[x].size(); i++ )
                        sp[i] = sp[i - 1] + v[x][i];

                    for ( int i = 0; i < v[x].size(); i++ )
                        for ( int j = i; j < v[x].size(); j++ )
                            best[x][j - i + 1] = max ( best[x][j - i + 1 ], sp[j] - sp[i] + v[x][i] );

                    //fout << best[x][1] << ' ';
                }

            for ( int i = 1; i <= t; i++ )
                for ( int w = 1; w <= cant; w++ )
                    for ( int lg = 1; lg <= v[i].size() && lg <= w; lg++ )
                        {
                            dp[i][w] = max ( dp[i][w], max ( dp[i - 1][w], dp[i - 1][w - lg] + best[i][lg] ) );
//                    fout <<"PENTRU "<< i << ' ' << w<<' '<<lg << '\n';
//                    fout << dp[i - 1][w] << ' ' << dp[i - 1][w - lg] + best[i][lg]<<' '<<dp[i][w] << '\n';;
                        }




            //fout << best[2][1] << ' ';
            fout << s - dp[t][cant] << '\n';
        }

    return 0;
}
