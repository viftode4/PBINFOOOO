#include <bits/stdc++.h>
using namespace std;
int q;
long long k;
long long n, poz[1000005];
string s;
int main()
{
    cin >> q;

    while( q )
        {
            q--;
            cin >> n >> k >> s;
            long long p = 0, x = 1;
            for(int i=1;i<=n;i++)
                poz[i]=-1;
            for( int i = 0; i < n; i++ )
                if( s[i] == '0' )
                    {
                        p++;
                        poz[p] = i;
                    }

            for( int i = 0; i < n && x <= p && k > 0; i++ )
                {
                    if( s[i] != '0' )
                        {
                            long long dist = poz[x] - i;
                            s[poz[x]] = 1;
                            poz[x] -= min( k, dist );
                            k -= min( k, dist );
                            x++;
                        }
                    else
                        x++;
                }

            x = 1;

            for( int i = 0; i < n; i++ )
                {
                    if( i == poz[x] )
                        {
                            cout << 0;
                            x++;
                        }
                    else
                        cout << 1;
                }

            cout << '\n';
        }

    return 0;
}
