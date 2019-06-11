#include <bits/stdc++.h>
using namespace std;
string s;
char sol[1000006];
int v = -1;
int main()
{
    cin >> s;

    for( int i = 0; s[i]; i++ )
        {
            v++;
            sol[v] = s[i];

            if( sol[v] == '<' )
                v -= 2;

            if( v < -1 )
                v = -1;
        }

    for( int i = 0; i <= v; i++ )
        cout << sol[i];

    return 0;
}
