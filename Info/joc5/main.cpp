#include <bits/stdc++.h>
using namespace std;
struct cub
{
    int f[6][3][3];
} s, f;
int ok( const cub x )
{
    for( int i = 1; i <= 6; i++ )
        {
            if( x[i][1][1] != f[i][1][1] )
                return 0;

            if( x[i][2][1] != f[i][2][1] )
                return 0;

            if( x[i][1][2] != f[i][1][2] )
                return 0;

            if( x[i][2][2] != f[i][2][2] )
                return 0;
        }

    return 1;
}
int m[100000];
int ant[100000];
queue<cub>q;
int sol[100000], v;
int main()
{
    for( int i = 1; i <= 6; i++ )
        {
            cin >> s[i][1][1] << s[i][1][2];
            cin >> s[i][2][1] << s[i][2][2];
        }

    for( int i = 1; i <= 6; i++ )
        {
            cin >> f[i][1][1] << f[i][1][2];
            cin >> f[i][2][1] << f[i][2][2];
        }

    q.insert( s );

    while( !q.empty() )
        {
            cub x = q.front();

            if( ok( x ) )
                {
                    int j = i;

                    while( j != 1 )
                        {
                            v++;
                            sol[v] = m[j];
                            j = ant[j];
                        }

                    break;
                }

        }

    fout << v << '\n';

    for( int i = v; i >= 1; i-- )
        fout << sol[i] << ' ';

    return 0;
}
