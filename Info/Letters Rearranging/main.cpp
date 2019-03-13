#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> s;
            int ok = 0, n = s.size();

            for( int j = 1; s[j]; j++ )
                {
                    if( s[j] != s[j - 1]  )
                        {
                            ok = 1;
                            break;
                        }
                }

            if( ok == 0 )
                cout << -1 << endl;
            else
                {
                    int ok = 0;

                    for( int j = 0; j <= n / 2; j++ )
                        if( s[j] != s[n - j - 1] )
                            {
                                //cout << j << ' ' << s[j] << ' ' << s[n - j];
                                ok = 1;
                                break;
                            }

                    if( ok == 0 )
                        {
                            for( int i = 1; i <= n / 2; i++ )
                                if( s[i] != s[0] )
                                    {
                                        swap( s[i], s[0] );
                                        break;
                                    }
                        }

                    cout << s << endl;
                }
        }

    return 0;
}
