#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
int t, n;
int a[200005], nu[200005];
string s[200005];
int main()
{
    cin >> t;

    while( t-- )
        {
            cin >> n;
            int d[5] = {0};
            vector<int>c[5];
            map<string, int>m;

            for( int i = 1; i <= n; i++ )
                {
                    nu[i] = 0;
                    cin >> s[i];
                    m[s[i]]++;

                    if( s[i][0] == s[i][s[i].size() - 1] && s[i][0] == '1' ) // 1 1
                        {
                            d[1]++;
                            c[1].push_back( i );
                        }
                    else if( s[i][0] == s[i][s[i].size() - 1] && s[i][0] == '0' ) //0 0
                        {
                            d[2]++;
                            c[2].push_back( i );
                        }
                    else if( s[i][0] != s[i][s[i].size() - 1] && s[i][0] == '1' ) //1 0
                        {
                            d[3]++;
                            c[3].push_back( i );
                        }
                    else if( s[i][0] != s[i][s[i].size() - 1] && s[i][0] == '0' ) //0 1
                        {
                            d[4]++;
                            c[4].push_back( i );
                        }

                    reverse( s[i].begin(), s[i].end() );
                    m[s[i]]++;
                    reverse( s[i].begin(), s[i].end() );
                }

            for( int i = 1; i <= n; i++ )
                if( m[s[i]] == 2 )
                    nu[i] = 1;

            if( ( d[1] && d[2] && !d[3] && !d[4] ) )
                {
                    cout << -1 << '\n';
                    continue;
                }

            int nr3 = 0, nr4 = 0;

            for( auto it : c[3] )
                if( !nu[it] )
                    nr3++;

            for( auto it : c[4] )
                if( !nu[it] )
                    nr4++;

            int mij = ( d[3] + d[4] ) / 2, cat;
            int sol1 = 0, sol2 = 0;

            if( d[3] <= mij )
                {
                    cat = mij - d[3];

                    if( cat <= nr4 )
                        {
                            cout << cat << '\n';

                            for( auto it : c[4] )
                                if( !nu[it] && cat )
                                    {
                                        cout << it << ' ';
                                        cat--;
                                    }

                            cout << '\n';
                        }
                    else
                        cout << -1 << '\n';
                }

            else if( d[4] <= mij )
                {
                    cat = mij - d[4];

                    if( cat <= nr3 )
                        {
                            cout << cat << '\n';

                            for( auto it : c[3] )
                                if( !nu[it] && cat )
                                    {
                                        cout << it << ' ';
                                        cat--;
                                    }

                            cout << '\n';
                        }
                    else
                        cout << -1 << '\n';
                }
        }

    return 0;
}
