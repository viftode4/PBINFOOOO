#include <bits/stdc++.h>
using namespace std;
int n, cer;
struct cub
{
    int f[5];
} a[20];
int sol[20][20];
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> a[i].f[1] >> a[i].f[2] >> a[i].f[3] >> a[i].f[4];

    fin >> cer;
    int m = ( int )( sqrt( n ) + 0.5 );
    return 0;
}
