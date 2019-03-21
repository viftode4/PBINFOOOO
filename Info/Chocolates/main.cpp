#include <bits/stdc++.h>
using namespace std;
long long n;
long long sum;
long long a[300000];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
        }

    long long mini = LLONG_MAX;

    for( int i = n; i > 0; i-- )
        {
            if( mini > a[i] )
                mini = a[i];
            else
                mini--;
            mini=max(0LL,mini);
            sum += mini;
        }

    cout << sum;
    return 0;
}
