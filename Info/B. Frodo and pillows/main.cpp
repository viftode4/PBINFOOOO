#include <bits/stdc++.h>
using namespace std;
int n, p, k;
int ok( int m )
{
    long long nrs, nrd, ss = 0, sd = 0;
    nrs = k - 1;
    nrd = n - k;
    long long i = m - 1;

    ss =  ( m - 1 + max( ( long long )0, m - max( ( long long ) 0, nrs ) ) )  * nrs / 2;
    sd = ( m - 1 +  max( ( long long )0, m - max( ( long long ) 0, nrd ) ) )  * nrd / 2;
    cout << m << ' ' << ss << ' ' << sd << endl;

    if( m + ss + sd <= p )
        return 1;

    return 0;
}
int main()
{
    cin >> n >> p >> k;
    long long l = 1;
    p = p - n;
    long long r = p;

    while( r - l > 1 )
        {
            int m = ( l + r ) / 2;
            cout << l << ' ' << r << " mij "  ;

            if( ok( m ) )
                l = m;
            else
                r = m;
        }

    if( ok( r ) )
        cout << r + 1;
    else
        cout << l + 1;

    return 0;
}
