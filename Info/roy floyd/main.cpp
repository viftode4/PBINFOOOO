#include <bits/stdc++.h>
using namespace std;
#define inf LLONG_MAX
#define ll long long
ifstream fin( "royfloyd.in" );
ofstream fout( "royfloyd.out" );
int n;
ll r[106][107];
void roy_floyd()
{
    for( int k = 1; k <= n; k++ )
        for( int i = 1; i <= n; i++ )
            for( int j = 1; j <= n; j++ )
                if( i != j && r[i][k] && r[k][j] && ( r[i][j] > r[i][k] + r[k][j] || !r[i][j] ) )
                    r[i][j] = r[i][k] + r[k][j];
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            fin >> r[i][j];

    roy_floyd();

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
                fout << r[i][j] << ' ';

            fout << '\n';
        }

    return 0;
}
