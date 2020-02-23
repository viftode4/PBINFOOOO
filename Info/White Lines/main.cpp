#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int n, k;
int a[1005][1005];
//0 cel mai mic
//1 cel mai mare
int r[1005][2];
int c[1005][2];
int w[1005][1005];
int sol = 0, smax = 0;
void smen( int cmin, int cmax, int rmin, int rmax )
{
    w[rmin][cmin]++;
    w[rmax + 1][cmax + 1]++;
    w[rmin][cmax + 1]--;
    w[rmax + 1][cmin]--;
}
int main()
{
    fast();
    cin >> n >> k;
    cin.get();

    for( int i = 1; i <= n; i++ )
        r[i][0] = r[i][1] = c[i][0] = c[i][1] = -1;

    for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
                {
                    char c;
                    cin.get( c );
                    a[i] = ( ( c == 'B' ) ? 1 : 0 );

                    if( c == 'B' )
                        {
                            if( r[i][0] == -1 )
                                r[i][0] = j;

                            if( r[i][1] == -1 )
                                r[i][1] = j;

                            r[i][0] = min( r[i][0], j );
                            r[i][1] = max( r[i][1], j );

                            if( c[i][0] == -1 )
                                r[i][0] = i;

                            if( c[i][1] == -1 )
                                r[i][1] = i;

                            c[i][0] = min( r[i][0], i );
                            c[i][1] = max( r[i][1], i );
                        }
                }

            cin.get();
        }

    for( int i = 1; i <= n; i++ )
        {
            int rmin, rmax, cmin, cmax;
            rmin = n;
            rmax = 0;
            cmin = n;
            cmax = 0;

            if( r[i][0] == -1 )
                sol++;

            rmin = n;
            rmax = 0;
            cmin = n;
            cmax = 0;

            if( c[i][0] == -1 )
                sol++;
        }

    for( int i = 1; i <= n; i++ )
        for( int j = 1; j <= n; j++ )
            {
            }

    return 0;
}
