#include <bits/stdc++.h>
using namespace std;
const int MOD = 7901;
int t, sum;
int n, a[1010];
int fact[1010];
int main()
{
    cin >> t;
    fact[0] = 1;

    for( int i = 1; i <= 1000; i++ )
        fact[i] = ( fact[i - 1] * i ) % MOD;

    while( t )
        {
            cin >> n;
            map<int, int>m;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> a[i];
                    m[a[i]]++;
                }

            sum = 1;

            for( auto it : m )
                {
                    int x = it.second;
                    sum = ( sum * fact[x] ) % MOD;
                }

            cout << sum << '\n';
            t--;
        }

    return 0;
}
