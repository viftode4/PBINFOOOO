#include <fstream>
#include <cstdio>
using namespace std;
int cer, n, x, k;
long long s;
FILE* fin;
FILE* fout;
int div ( int x, int k )
{
    int cx = x, t = 0, i;
    if ( cx % 2 == 0 )
    {
        t++;
        while ( cx % 2 == 0 )
            cx = cx / 2;

    }
    if ( t == k )
        return 2;
    for (  i = 3; i * i <= x && t != k; i += 2 )
        if ( cx % i == 0 )
        {
            t++;
            while ( cx % i == 0 )
                cx = cx / i;
        }
    if ( t == k )
        return i - 2;
    if ( cx == x )
        return x;
    else if ( cx > 1 )
        return cx;

}
int main()
{
    fin = fopen ( "cufar.in", "r" );
    fout = fopen ( "cufar.out", "w" );
    fscanf ( fin, "%d%d", &cer, &n );
    if ( cer == 1 )
    {
        fscanf ( fin, "%i%i", &x, &k );
        fprintf ( fout, "%i", div ( x, k ) );
        return 0;
    }
    for ( int i = 1; i <= n; i++ )
    {
        fscanf ( fin, "%i%i", &x, &k );
        s = s + div ( x, k );
    }
    fprintf ( fout, "%d", s );
    return 0;
}
