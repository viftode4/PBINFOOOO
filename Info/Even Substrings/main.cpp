#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
long long sum;
int main()
{
    cin >> n;
    cin >> s;

    for( int i = 0; i < n; i++ )
        {
            int x = s[i] - '0';

            if( x % 2 == 0 )
                sum += ( i + 1 );
        }

    cout << sum;
    return 0;
}
