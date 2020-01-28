#include <bits/stdc++.h>
using namespace std;
vector<int>pos[30];
int n, m;
string s, x;
int main()
{
    cin >> n >> s;
    cin >> m;

    for( int i = 0; i < n; i++ )
        pos[s[i] - 'a'].push_back( i + 1 );

    for( int i = 1; i <= m; i++ )
        {
            cin >> x;
            int fr[30] = {0};

            for( int i = 0; x[i]; i++ )
                fr[x[i] - 'a']++;

            int sol = 0;

            for( int i = 0; i < 30; i++ )
                if( fr[i] )
                    sol = max( sol, pos[i][fr[i] - 1] );

            cout << sol << '\n';
        }

    return 0;
}
