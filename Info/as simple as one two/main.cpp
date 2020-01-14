#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
int t, n;
int a[200005];
vector<int>sol;
string s;
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> s;
            sol.clear();

            for( int i = 0; i < ( int )( s.size() - 2 ); i++ )
                {

                    if( s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e' )
                        {
                            s[i + 1] = '0';
                            sol.push_back( i + 2 );
                        }

                    if( s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' )
                        {
                            int j = i + 2;

                            if ( j + 2 < s.size() )
                                {
                                    if( s[j] == 'o' && s[j + 1] == 'n' && s[j + 2] == 'e' )
                                        {
                                            sol.push_back( i + 3 );
                                            s[i + 2] = '0';
                                        }
                                    else
                                        {
                                            sol.push_back( i + 2 );
                                            s[i + 1] = '0';
                                        }
                                }
                            else
                                {
                                    sol.push_back( i + 2 );
                                    s[i + 1] = '0';
                                }

                        }
                }

            cout << sol.size() << '\n';

            for( auto it : sol )
                cout << it << ' ';

            cout << '\n';
        }

    return 0;
}
