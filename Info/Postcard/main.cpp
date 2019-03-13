#include <bits/stdc++.h>
using namespace std;
int n, nrc, nrs;
string c;
int main()
{
    cin >> c;
    cin >> n;

    for( int i = 0; c[i]; i++ )
        {
            if( c[i] == '?' )
                nrc++;
            else if( c[i] == '*' )
                nrs++;
        }

    int s = c.size() - nrs - nrc;

    if( n > s )
        {
            if( nrs == 0 )
                {
                    cout << "Impossible";
                    return 0;
                }
            else
                {
                    int ok = 1;

                    for( int i = 0; c[i]; i++ )
                        {
                            if( c[i] == '*' && ok == 1 )
                                {
                                    ok = 0;

                                    for( int j = 1; j <= n - s; j++ )
                                        cout << c[i - 1];
                                }
                            else if( c[i] != '?' && c[i] != '*' )
                                cout << c[i];
                        }
                }
        }
    else if( s > n )
        {
            if( nrc + nrs + n >= s )
                {
                    int ok = s - n;

                    for( int i = 0; c[i]; i++ )
                        if( c[i] != '*' && c[i] != '?' )
                            {
                                if( c[i + 1] != '*' && c[i + 1] != '?' )
                                    cout << c[i];
                                else if( c[i + 1] == '*' && ok > 0 || c[i + 1] == '?' && ok > 0 )
                                    ok--;
                                else if( c[i + 1] == '*' && ok == 0 || c[i + 1] == '?' && ok == 0 )
                                    cout << c[i];
                            }
                }
            else
                cout << "Impossible";
        }
    else if( n == s )
        {
            for( int i = 0; c[i]; i++ )
                if( c[i] != '*' && c[i] != '?' )
                    cout << c[i];
        }

    return 0;
}
