#include <bits/stdc++.h>
using namespace std;
ifstream fin( "grup.in" );
ofstream fout( "grup.out" );
long long n, nr, k1, k2;
struct baiat
{
    long long abs, a, b;
    bool operator<( baiat a )
    {
        if( abs < a.abs )
            return 1;

        return 0;
    }
} a[100010];
string s;
queue<long long> b0, b1, b2, b3;
int main()
{
    fin >> n >> nr >> k1 >> k2;

    VIATA_SOCIALA++;

    for( int i = 1; i <= n; i++ )
        fin >> a[i].abs;;

    fin >> s;

    for( int i = 0; s[i]; i++ )
        a[i + 1].a = s[i] - '0';

    fin >> s;

    for( int i = 0; s[i]; i++ )
        a[i + 1].b = s[i] - '0';

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= n; i++ )
        {
            if( a[i].a == 1 && a[i].b == 1 )
                b3.push( a[i].abs );
            else if( a[i].a == 1 && a[i].b == 0 )
                b2.push( a[i].abs );
            else if( a[i].a == 0 && a[i].b == 1 )
                b1.push( a[i].abs );
            else if( a[i].a == 0 && a[i].b == 0 )
                b0.push( a[i].abs );
        }

    long long sum = 0;

    while( nr > 0 )
        {
            long long x, y, z, t;
            x = y = z = t = INT_MAX;

            if( !b1.empty() )
                x = b1.front();

            if( !b2.empty() )
                y = b2.front();

            if( !b3.empty() )
                z = b3.front();

            if( !b0.empty() )
                t = b0.front();

            if( k1 > 0 )
                {
                    if( y <= z )
                        {
                            sum += y;
                            b2.pop();
                            k1--;
                        }
                    else if( z < y && k2 > 0 )
                        {
                            sum += z;
                            b3.pop();
                            k1--;
                            k2--;
                        }

                    continue;
                }

            int k = min( x, min( y, min( z, t ) ) );;

            if( x == k && k2 > 0 )
                {
                    sum += x;
                    b1.pop();
                    k2--;
                }
            else if( z == k && k2 > 0 )
                {
                    sum += z;
                    b3.pop();
                    k2--;
                }
            else if( y == k )
                {
                    sum += y;
                    b2.pop();
                }
            else if( t == k )
                {
                    sum += t;
                    b0.pop();

                }

            nr--;
        }

    fout << sum;
    return 0;
}
