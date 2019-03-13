#include <bits/stdc++.h>
using namespace std;
long long n;
set<long long> s;
queue<long long> q;
int main()
{
    cin >> n;
    s.insert( n * ( n + 1 ) / 2 );
    s.insert( 1 );
    q.push( 1 );

    for( int i = 2; i * i <= n; i++ )
        if( n % i == 0 )
            {
                if( i != n / i )
                    q.push( i );

                q.push( n / i );
            }

    q.push( n );

    while( !q.empty() )
        {
            int k = q.front();
            q.pop();
            long long i = 1, sum = 0;
            long long ul = n + 1 - k;
            long long nrt = ( ul - 1 ) / k + 1;
            sum = ( ul + 1 ) * nrt / 2;
            s.insert( sum );
        }

    for( auto it : s )
        cout << it << ' ';

    return 0;
}
