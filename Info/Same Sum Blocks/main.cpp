#include <bits/stdc++.h>
using namespace std;
struct bloc
{
    int st, dr;
};
map<int, vector<bloc>>m;
vector<bloc> bun;
int v[1510], n, cmax;
int s[1510];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> v[i];
            s[i] = s[i - 1] + v[i];
        }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= i; j++ )
            {
                bloc x;
                x.st = j;
                x.dr = i;
                int sum = s[i] - s[j - 1];
                m[sum].push_back( x );
                // cout << i << ' ' << j << ' ' << sum << '\n';
            }

    for( auto sum : m )
        {
            vector <bloc> x = sum.second;
            //cout << sum.first << ' ';
            int c = 0;
            int dr = -123;
            vector<bloc> p;

            for( auto b : x )
                {
                    //cout << b.st << ' ' << b.dr << '\n';

                    if( b.st > dr )
                        {
                            dr = b.dr;
                            c++;
                            p.push_back( b );
                        }
                }

            // cout << c << '\n';

            if( c > cmax )
                {
                    cmax = c;
                    bun = p;
                }
        }

    cout << cmax << '\n';

    for( auto it : bun )
        cout << it.st << ' ' << it.dr << '\n';

    return 0;
}
