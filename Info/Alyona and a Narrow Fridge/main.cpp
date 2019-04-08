#include <bits/stdc++.h>
using namespace std;
unsigned long long n, h;
unsigned long long c[1004];
const int INF = INT_MAX;
int ok( int x )
{
    vector<int>v;

    for( int i = 1; i <= x; i++ )
        v.push_back( c[i] );

    sort( v.begin(), v.end(), greater<int>() );
    unsigned long long hv = 0;

    for( int i = 0; i < x; i = i + 2 )
        hv += v[i];


    //cout << "LA " << x << ' ' << hv << '\n';

    if( hv > h )
        return 0;

    return 1;
}
unsigned long long caut()
{
    unsigned long long l = 0, r = n;

    while( r - l > 1 )
        {
            unsigned long long mid = ( l + r ) / 2;
            //cout << l << ' ' << r << ' ' << mid << ' ' << '\n';

            if( ok( mid ) )
                l = mid;
            else
                r = mid - 1;
        }

    return r;
}
int main()
{
    cin >> n >> h;
    c[0] = c[n + 1] = INF;

    for( int i = 1; i <= n; i++ )
        cin >> c[i];

    unsigned long long k = caut();
    cout << k;
    return 0;
}
