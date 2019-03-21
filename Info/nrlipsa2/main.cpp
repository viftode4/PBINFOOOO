#include <bits/stdc++.h>
using namespace std;
ifstream fin( "nrlipsa2.in" );
ofstream fout( "nrlipsa2.out" );
int x, nmin = 9999;
int a[300];
int main()
{
    while( fin >> x )
        if( x >= -100 && x <= 100 )
            {
                x += 100;
                a[x]++;
            }

    for( int i = 0; i <= 200; i++ )
        if( a[i] == 0 )
            {
                fout << i - 100;
                return 0;
            }

    return 0;
}
