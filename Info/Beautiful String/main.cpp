#include <bits/stdc++.h>
using namespace std;
int n;
char s[100005];
char care( int pos )
{
    if( s[pos - 1] != 'a' && s[pos + 1] != 'a' )
        return 'a';

    if( s[pos - 1] != 'b' && s[pos + 1] != 'b' )
        return 'b';

    if( s[pos - 1] != 'c' && s[pos + 1] != 'c' )
        return 'c';

}
int main()
{
    cin >> n;

    while( n-- )
        {
            cin >> s;
            int ok = 1, nr = 0;

            for( int i = 0; s[i]; i++ )
                {
                    if( s[i] == s[i - 1] && s[i] != '?' )
                        ok = 0;

                    if( s[i] == '?' )
                        nr++;
                    else
                        {
                            while( nr >= 1 )
                                {
                                    if( i - nr >= 0 )
                                        s[i - nr] = care( i - nr );
                                    else
                                        s[i] = 'a';

                                    nr--;
                                }

                            nr = 0;
                        }
                }
        int i = strlen( s );

            while( nr >= 1 )
                {
                    if( i - nr >= 0 )
                        s[i - nr] = care( i - nr );
                    else
                        s[i] = 'a';

                    nr--;
                }

            if( !ok )
                cout << -1 << '\n';
            else
                cout << s << '\n';
        }

    return 0;
}
