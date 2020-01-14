#include <bits/stdc++.h>
using namespace std;
int k;
int n;
string a, b;
map<char, vector<int> > m;
vector<pair<int, int>>sol;
int main()
{
    cin >> k;

    while( k-- )
        {
            cin >> n;
            cin >> a >> b;
            sol.clear();

            for( int i = 0; i < n - 1; i++ )
                {
                    //cout << a << ' ' << b << '\n';

                    if( a[i] != b[i] )
                        {
                            int ok = 0;

                            for( int j = i + 1; j < n; j++ )
                                if( a[i] == a[j] )
                                    {
                                        swap( a[j], b[i] );
                                        sol.push_back( make_pair( j + 1, i + 1 ) );
                                        ok = 1;
                                        break;
                                    }

                            if( !ok )
                                {

                                    sol.push_back( make_pair( i + 1, i + 1 ) );
                                    swap( a[i], b[i] );

                                    for( int j = i + 1; j < n; j++ )
                                        if( a[i] == a[j] )
                                            {
                                                swap( a[j], b[i] );
                                                sol.push_back( make_pair( j + 1, i + 1 ) );
                                                break;
                                            }

                                }

                        }
                }

            if( a == b )
                {
                    cout << "Yes\n";
                    cout << sol.size() << '\n';

                    for( auto it : sol )
                        cout << it.first << ' ' << it.second << '\n';
                }
            else
                cout << "No\n";

        }

    return 0;
}
