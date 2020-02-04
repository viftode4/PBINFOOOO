#include <bits/stdc++.h>
using namespace std;
int n, k, nr, sol;
int fr[5000];
int main()
{
    cin >> n >> k;
    nr = n % 2;

    for( int i = 1; i <= n; i++ )
        {
            int x;
            cin >> x;
            fr[x]++;
        }

    for( int i = 1; i <= k; i++ )
        {
            sol += fr[i] - fr[i] % 2;
            nr += fr[i] % 2;
        }

    sol += nr / 2;
    cout << sol;
    return 0;
}
