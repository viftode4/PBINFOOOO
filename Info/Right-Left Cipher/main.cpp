#include <bits/stdc++.h>
using namespace std;
string s, sol;
int main()
{
    cin >> s;
    int n = s.size();

    if( n % 2 == 1 )
        {
            sol = s[n / 2];

            for( int i = n / 2 + 1 ; i < n; i++ )
                {
                    sol += s[i];
                    sol += s[n - i - 1];
                }

        }
    else
        {
            sol = s[n / 2 - 1];

            if( n > 1 )
                sol = s[n / 2 - 1];

            for( int i = n / 2 ; i < n; i++ )
                {
                    sol += s[i];

                    if( n - i - 2 >= 0 )
                        sol += s[n - i - 2];
                }
        }

    cout << sol;
    return 0;
}
