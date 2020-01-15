#include <bits/stdc++.h>
using namespace std;
ifstream fin( "piscina.in" );
ofstream fout( "piscina.out" );
int n, m;
int p;
long long aria;
struct pct
{
    int i, j;
    bool operator<( const pct& x )const
    {
        if( x.j != j )
            return x.j > j;
        else
            return x.i > i;
    }
} a[100005];
void aaa()
{
    sort( a + 1, a + p + 1 );
    aria = max( aria, 1LL * a[1].j * n );
    int mini = a[1].i;

    for( int i = 2; i <= p; i++ )
        {
            aria = max( aria, 1LL * mini * a[i].j );
            mini = min( mini, a[i].i );
        }
}
void hr()
{
    for( int i = 2; i < p; i++ )
        a[i].i = n - a[i].i;
}
void vr()
{
    for( int i = 2; i < p; i++ )
        a[i].j = m - a[i].j;
}
int main()
{
    fin >> n >> m >> p;

    for( int i = 1; i <= p; i++ )
        fin >> a[i].i >> a[i].j;

    a[p + 1].i = n;
    a[p + 1].j = 0;
    a[p + 2].i = 0;
    a[p + 2].j = m;
    p += 2;
    aaa();
    hr();
    aaa();
    vr();
    aaa();
    hr();
    aaa();
    fout << aria;
    return 0;
}
