#include <bits/stdc++.h>
using namespace std;
long long n, k, op, x;
vector<int>a;
long long mi, mx, dif = INT_MAX;
map<int, int>m;
int main()
{
    cin >> n >> k;

    for( int i = 0; i < n; i++ )
        {
            cin >> x;
            a.push_back( x );

            if( !mi )
                mi = x;

            mi = min( mi, x );
            mx = max( mx, x );
            m[x]++;
        }


    sort( a.begin(), a.end() );
    auto it = unique( a.begin(), a.end()  );
    a.erase( it, a.end() );
    n = a.size();
    long long s = 0, f = n - 1;

    while( ( op + m[mi] <= k || op + m[mx] <= k ) && ( s < n && f > -1 ) && s <= f )
        {
            dif = min( dif, abs( mx - mi ) );

            if( m[mi] < m[mx] )
                {
                    long long cat = a[s + 1] - a[s];

                    if( m[mi]*cat + op > k )
                        {
                            long long l = 0, r = cat + 1;

                            while( r - l > 1 )
                                {
                                    long long mid = ( l + r ) / 2;

                                    if( m[mi]*mid + op <= k )
                                        l = mid;
                                    else
                                        r = mid - 1;
                                }

                            op += m[mi] * l;
                            m[mi + l] += m[mi];
                            mi += l;
                        }
                    else
                        {
                            m[mi + cat] += m[mi];
                            op += m[mi] * cat;
                            mi += cat;
                        }

                    s++;
                }
            else
                {
                    long long cat = a[f] - a[f - 1];

                    if( m[mx]*cat + op > k )
                        {
                            long long l = 0, r = cat + 1;

                            while( r - l > 1 )
                                {
                                    long long mid = ( l + r ) / 2;

                                    if( m[mx]*mid + op <= k )
                                        l = mid;
                                    else
                                        r = mid - 1;
                                }

                            op += m[mx] * l;
                            m[mx - l] += m[mx];
                            mx -= l;
                        }
                    else
                        {
                            m[mx - cat] += m[mx];
                            op += m[mx] * cat;
                            mx -= cat;
                        }

                    f--;
                }

            dif = min( dif, abs( mx - mi ) );
        }

    cout << dif;
    return 0;
}
