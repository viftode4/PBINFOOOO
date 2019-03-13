#include <bits/stdc++.h>
using namespace std;
int n, fr[4];
string s;
int main()
{
    cin >> n;
    cin >> s;

    for( int i = 0; s[i]; i++ )
        fr[s[i] - '0']++;

    if( fr[0] < n / 3 )
        {
            for( int i = 0; i < n && fr[0] < n / 3; i++ )
                if( fr[s[i] - '0'] > n / 3 )
                    {
                        s[i] = '0';
                        fr[0]++;
                        fr[s[i]]--;
                    }

        }

    if( fr[2] < n / 3 )
        {
            for( int i = n - 1; i >= 0 && fr[2] < n / 3; i-- )
                if( fr[s[i] - '0'] > n / 3 )
                    {
                        s[i] = '2';
                        fr[2]++;
                        fr[s[i]]--;
                    }

        }

    if( fr[1] < n / 3 )
        {
            for( int i = n - 1; i >= 0 && fr[1] < n / 3; i-- )
                if( fr[s[i] - '0'] > n / 3 )
                    {
                        s[i] = '1';
                        fr[1]++;
                        fr[s[i]]--;
                    }

        }


    cout << s;
    return 0;
}
