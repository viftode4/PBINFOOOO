#include <bits/stdc++.h>
using namespace std;
ifstream fin( "shell.in" );
ofstream fout( "shell.out" );
long long n, a, b, g;
long long m[4][4], sum[4];
long long nr;
int main()
{
    fin >> n;
    m[1][1] = m[2][2] = m[3][3] = 1;

    for( int i = 1; i <= n; i++ )
        {
            fin >> a >> b >> g;

            for( int j = 1; j <= 3; j++ )
                swap( m[j][a], m[j][b] );

            for( int j = 1; j <= 3; j++ )
                if( m[j][g] == 1 )
                    sum[j]++;
        }

    for( int i = 1; i <= 3; i++ )
        nr = max( sum[i], nr );

    fout << nr;
    return 0;
}
