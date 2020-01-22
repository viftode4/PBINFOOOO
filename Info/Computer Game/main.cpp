#include <bits/stdc++.h>
using namespace std;
int t;
long long k, n, a, b;
int ok( long long x )
{
    long long sum = k;
    sum -= x * a;
    sum -= ( n - x ) * b;

    if( sum > 0 )
        return 1;
    else
        return 0;
}
long long cauta()
{
    long long l = -1, r = n + 1;

    while( r - l > 1 )
        {
            long long mid = ( l + r ) / 2;

            if( ok( mid ) )
                l = mid;
            else
                r = mid;
        }

    return l;
}
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> k >> n >> a >> b;
            long long cat = cauta();
            cout << cat << '\n';
        }

    return 0;
}
