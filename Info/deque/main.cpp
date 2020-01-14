#include <bits/stdc++.h>
using namespace std;
ifstream fin( "deque.in" );
ofstream fout( "deque.out" );
int cost[5000005];
deque<int> q;
int k, n, x;
long long sum = 0;
int main()
{
    fin >> n >> k;
    fin >> cost[1];
    q.push_back( 1 );
    for( int i = 2; i <= n; i++ )
        {
            fin >> cost[i];

            while( !q.empty() && cost[q.back()] >= cost[i] )
                q.pop_back();

            q.push_back( i );

            while( q.front() <= i - k && !q.empty() )
                q.pop_front();

            if( i >= k )
                sum += cost[q.front()];

        }

    fout << sum;
    return 0;
}
