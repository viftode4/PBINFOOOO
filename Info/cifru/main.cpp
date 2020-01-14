#include <bits/stdc++.h>
using namespace std;
#define MOD 19997
int C[]
int dp[2020];
vector<int>dvz;
int n, k;
int main()
{

    fin >> n >> k;

    for( int i = 1; i * i <= k; i++ )
        if( k % i == 0 )
            {
                dvz.push_back( i );
                dvz.push_back( k / i );
            }

    return 0;
}
