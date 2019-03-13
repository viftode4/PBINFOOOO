#include <bits/stdc++.h>
using namespace std;
int v, n;
string s;
char a[5][5];
int use[5][5];
int di[6] = {0, 0, 1, 0, -1};
int dj[6] = {0, 1, 0, -1, 0};
int caut( int i, int j )
{
    int ok;
    v++;

    if( v >= s.size() )
        return 1;

    for( int d = 1; d <= 4; d++ )
        if( a[i + di[d]][j + dj[d]] == s[v] && !use[i + di[d]][j + dj[d]] )
            {
                use[i + di[d]][j + dj[d]] = 1;
                ok = caut( i + di[d], j + dj[d] );
                use[i + di[d]][j + dj[d]] = 0;

                if( ok == 1 )
                    return 1;
            }

    return 0;
}
int main()
{
    cin >> a[1];
    cin >> a[2];
    cin >> a[3];
    cin >> a[4];
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> s;
            v = 0;
            int ok = 0;

            for( int i = 0; i <= 3; i++ )
                for( int j = 0; j <= 3; j++ )
                    if( s[v] == a[i][j] )
                        {
                            use[i][j] = 1;
                            ok = caut( i, j );
                            use[i][j] = 0;

                            if( ok == 1 )
                                break;
                        }

            cout << s << ':' << ' ';

            if( ok == 1 )
                s = "YES";
            else
                s = "NO";

            cout << s << endl;
        }

    return 0;
}
