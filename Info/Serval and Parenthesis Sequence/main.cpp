#include <bits/stdc++.h>
using namespace std;
int n, nri, nrd, nrs;
string s;
int main()
{
    cin >> n >> s;

    for( auto it : s )
        if( it == '(' )
            nrd++;
        else if( it == ')' )
            nri++;
        else
            nrs++;

    if( ( nrs - abs( nri - nrd ) ) % 2 == 1 )
        {
            cout << ":(";
            return 0;
        }

    for( int i = 0; i < n; i++ )
        if( s[i] == '?' )
            {
                if( nrd < n / 2 )
                    {
                        s[i] = '(';
                        nrd++;
                    }
                else
                    {
                        s[i] = ')';
                        nri++;
                    }
            }

    int v[300005], p = 1;

    if( s[0] == '(' )
        v[p] = 1;
    else
        v[p] = 0;

    for( int i = 1; i < n; i++ )
        {
            if( p == 0 )
                {
                    cout << ":(";
                    return 0;
                }

            p++;

            if( s[i] == '(' )
                v[p] = 1;
            else
                v[p] = 0;

            while( v[p] == 0 && v[p - 1] == 1 )
                p -= 2;
        }

    if( p == 0 )
        cout << s;
    else
        cout << ":(";

    return 0;
}
