#include <bits/stdc++.h>
using namespace std;
string a, b;
int s[1000006], nr, sol;
int main()
{
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    for( int i = 0; a[i]; i++ )
        {
            if( i > 0 )
                {
                    if( a[i] == '1' )
                        s[i] = s[i - 1] + 1;
                    else
                        s[i] = s[i - 1];
                }
            else
                {
                    if( a[i] == '1' )
                        s[i] = 1;
                    else
                        s[i] = 0;
                }
        }

    for( int i = 0; b[i]; i++ )
        if( b[i] == '1' )
            nr++;

    for( int i = 0; i < n - m+1; i++ )
        if( i > 0 )
            {
                if( nr % 2 == ( s[i + m - 1] - s[i - 1] ) % 2 )
                    sol++;
            }
        else
            {
                if( nr % 2 == ( s[m - 1] ) % 2 )
                    sol++;
            }

    cout << sol;
    return 0;
}
