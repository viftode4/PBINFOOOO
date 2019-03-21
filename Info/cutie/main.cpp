#include <bits/stdc++.h>
using namespace std;
ifstream fin( "cutie.in" );
ofstream fout( "cutie.out" );
struct bila
{
    int st, dr;
} b[10005];
int x = 1, t, n, k, m, nr1, nr2, nr3;
int a[10005];
bila caut( const int z )
{
    int l = 0, r = x + 1;

    while( r - l > 1 )
        {
            int mid = ( l + r ) / 2;

            if( a[mid] < z )
                l = mid;
            else
                r = mid;
        }

    bila y;
    y.st = abs( z - a[r - 1] );
    y.dr = abs( z - a[r] );
    return y;
}
int main()
{
    fin >> t;

    while( t )
        {
            nr1 = nr2 = nr3 = 0;
            fin >> n >> k >> m;
            x = 1;
            int z;
            a[x] = 1;

            for( int i = 1; i <= k; i++ )
                {
                    fin >> z;
                    a[++x] = z;
                }

            a[++x] = n;
            int nrm = 0;

            for( int i = 1; i <= m; i++ )
                {
                    fin >> z;
                    b[i] = caut( z );
                    // fout << "BILA " << i << '\n';
                    //fout << "PANA IN ST " << b[i].st << '\n' << "PANA IN DR " << b[i].dr << '\n';
                }

            for( int i = 1; i <= m; i++ )
                {
                    if( b[i].st % 2 == 0 && b[i].dr % 2 == 0 )
                        nr1++;
                    else if( b[i].st % 2 == 1 && b[i].dr % 2 == 1 )
                        nr2++;
                    else  if( b[i].st % 2 != b[i].dr % 2 )
                        nr3++;
                }

            //fout << '\n' << nr1 << ' ' << nr2 << ' ' << nr3 << '\n';
            int par = nr2 % 2;

            if( par == 1 )
                fout << 1;
            else
                {
                    if( nr3 % 2 == 1 )
                        fout << 1;
                    else
                        fout << 0;
                }

            --t;
        }

    return 0;
}
