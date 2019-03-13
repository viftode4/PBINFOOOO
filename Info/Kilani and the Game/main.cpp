#include <bits/stdc++.h>
using namespace std;
int n, m, p;
int a[1010][1010];
int f[11][1010][1010];
int di[] = {0, -1, 0, 1, 0};
int dj[] = {0, 0, 1, 0, -1};
int s[11];
char c;
struct start
{
    int x, y;
} st[11];
int main()
{
    cin >> n >> m >> p;

    for( int i = 1; i <= p; i++ )
        cin >> s[i];

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= m; j++ )
            {
                cin >> c;

                if( c == '.' )
                    a[i][j] = 0;
                else if( c == '#' )
                    {
                        a[i][j] = -1;

                        for( int k = 1; k <= p; k++ )
                            f[k][i][j] = -1;
                    }
                else
                    {
                        int x = stoi( c );
                        a[i][j] = x;

                    }
            }

    return 0;
}
