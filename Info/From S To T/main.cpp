#include <bits/stdc++.h>
using namespace std;
int n;
string s, t, p;
int main()
{
    cin >> n;

    while( n-- )
        {
            cin >> s >> t >> p;
            int j = 0;

            for( int i = 0; t[i]; i++ )
                if( t[i] == s[j] && j < s.size() )
                    j++;

            if( j == s.size() )
                {
                    int fr[30] = {0};

                    for( int i = 0; p[i]; i++ )
                        fr[p[i] - 'a']++;

                    for( int i = 0; s[i]; i++ )
                        fr[s[i] - 'a']++;

                    for( int i = 0; t[i]; i++ )
                        fr[t[i] - 'a']--;

                    string x = "YES\n";

                    for( int i = 0; t[i]; i++ )
                        if( fr[t[i] - 'a'] < 0 )
                            x = "NO\n";

                    cout << x;
                }
            else
                cout << "NO\n";
        }

    return 0;
}
