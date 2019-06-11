#include <bits/stdc++.h>
using namespace std;
int n;
int dp[100][3];
int main()
{
    cin >> n;

    if( n % 2 == 0 )
        {
            unsigned long long var = 1;
            int cat = n / 2;

            while( cat )
                {
                    cat--;
                    var = var * 2 * 1ULL;
                }

            cout << var;
        }
    else
        cout << 0;

    return 0;
}
