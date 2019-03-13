#include <bits/stdc++.h>
using namespace std;
string s;
int f[300];
int nr1, nr2, nr;
int main()
{
    cin >> s;

    for( int i = 0; s[i]; i++ )
        {
            f[s[i]]++;
            nr++;
        }

    for( int i = 0; i <= 299; i++ )
        {
            if( f[i] % 2 == 0 )
                nr2++;
            else
                nr1++;
        }

    if( nr1 > nr % 2 )
        {
            cout << "Impossible";
            return 0;
        }

    return 0;
}
