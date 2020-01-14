#include <bits/stdc++.h>

using namespace std;
char s[400];
int main()
{
    cin.getline( s, 255 );

    for( int i = 0; s[i]; i++ )
        if( strchr( "aeiou", s[i] ) != NULL )
            {
                //strcpy( s + i + 1, s + i );
                //cout << s + i + 1 << ' ' << s + i << ' ';
                i++;
            }

    cout << s;
    return 0;
}
