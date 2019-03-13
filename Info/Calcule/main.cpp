#include <bits/stdc++.h>
using namespace std;
ifstream fin( "calcule.in" );
ofstream fout( "calcule.out" );
int n, k, fr[100010];
int x, nr;
vector <int> a[100010];
int main()
{
    fin >> n >> k;
    int m = 1, nr = 0;
    fr[0]++;

    for( int i = 0; i <= n; i++ )
        a[i].push_back( 0 );

    for( int i = 1; i <= n; i++ )
        {
            fin >> x;
            nr = ( nr + x ) % k;
            fr[nr]++;
            int ok = 0;

            for( int j = 1; j <= m; j++ )
                if( x > a[j].back() )
                    {
                        a[j].push_back( x );
                        ok = 1;
                        break;
                    }

            if( ok == 0 )
                {
                    m++;
                    a[m].push_back( x );
                }
        }

    fout << m << endl;
    unsigned long long s = 0;

    for( int i = 0; i <= k - 1; i++ )
        s += ( fr[i] - 1 ) * ( fr[i] ) / 2;

    fout << s;
    return 0;
}
