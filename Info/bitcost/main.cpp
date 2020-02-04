#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "bitcost.in" );
ofstream fout ( "bitcost.out" );
long long v[100], dp[100];
long long a, b, q, n;
long long div ( long long s, long long d, long long sum, int i )
{
    long long x = s + 1LL * ( 1LL << ( i ) ) - 1LL;

    if (  s >= a && x <= b )
        return sum + dp[i];

    if ( s > b || d < a )
        return -1LL * LLONG_MAX;

    if ( i == 0 )
        return sum;

    return max ( div ( s, d - 1LL * ( 1LL << ( i - 1 ) ), sum, i - 1 ), div ( s + 1LL * ( 1LL << ( i - 1 ) ), d, sum + v[i], i - 1 ) );
}
int main()
{
    fin >> n >> q;

    for ( int i = 1; i <= n; i++ )
        {
            fin >> v[i];
            dp[i] = max ( dp[i - 1], dp[i - 1] + v[i] );
        }

    while ( q )
        {
            q--;
            fin >> a >> b;
            fout << div ( 0LL, 1LL * ( 1LL << ( n + 1 ) ) - 1, 0LL, n ) << '\n';
        }

    return 0;
}
