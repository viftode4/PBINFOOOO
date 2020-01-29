#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int>a;
int main()
{
    cin >> n >> k;

    for( int i = 1; i <= n; i++ )
        {
            cout << "? ";

            for( int j = 1; j <= k + 1; j++ )
                {
                    if( i == j )
                        continue;

                    cout << j << ' ';
                }

            cout << endl;
            int pos = 0, el = 0;
            cin >> pos >> el;
            a.push_back( el );
        }

    sort( a.begin(), a.end() );

    for( int i = 0; i < a.size(); i++ )
        if( a[i] != a[i + 1] )
            {
                cout << "! " << a.size() - i - 1 << endl;;
                break;
            }

    return 0;
}
