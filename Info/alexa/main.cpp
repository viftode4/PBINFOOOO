#include <bits/stdc++.h>

using namespace std;
char s[3000];
char sol[3000];
int main()
{

    cin.getline( s, 3000 );
    strcpy( sol, s );

    for( int i = 0; s[i]; i++ )
        if( s[i] > 'Z' )
            s[i] = s[i] - ' ';

    int ok = 1;

    while( ok )
        {
            ok = 0;

            for( int i = 0; s[i]; i++ )
                {
                    int j = i;

                    while( s[i] == s[j + 1] && s[j] )
                        j++;

                    if( j - i > 0 )
                        {
                            ok = 1;
                            strcpy( s + i, s + j + 1 );
                            strcpy( sol + i, sol + j + 1 );
                            break;
                        }
                }
        }

    cout << sol;
    return 0;
}
