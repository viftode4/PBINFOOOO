#include <bits/stdc++.h>
using namespace std;
ifstream fin( "cifreord.in" );
ofstream fout( "cifreord.out" );
int n, x;
int a[111];
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> x, a[x]++;

    int nr = 0;

    for( int i = 0; i <= 9; i++ )
        while( a[i] )
            {
                fout << i << ' ';
                nr++;

                if( nr == 20 )
                    {
                        nr = 0;
                        fout << '\n';
                    }

                a[i]--;
            }

    return 0;
}
