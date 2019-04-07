#include <bits/stdc++.h>
using namespace std;
int n;
long long sum;
long long f( int x )
{
    long long r = 1;

    while( x )
        {
            r = r * 3;
            x--;
        }

    return r;
}
int main()
{
    cin >> n;
    sum = 1;

    for( int i = 1; i <= n; i++ )
        {
            sum += i * 2;
        }

    cout << sum;
    return 0;
}
