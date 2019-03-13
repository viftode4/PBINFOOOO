#include <bits/stdc++.h>
using namespace std;
ifstream fin( "mountains.in" );
ofstream fout( "mountains.out" );
const int N = 1e6;
long long n, v, x, y;
struct m
{
    long long x, y;
} q[N], a, b[N];
int inter( m a, m b )
{
    long long s = a.y - b.y;
    long long s1 = a.x - s;
    long long s2 = a.x + s;

    //b in inter lui a
    if( b.x >= s1 && b.x <= s2 )
        return 1;

    return 0;
}
int cond ( m a, m b )
{
    if( a.x < b.x )
        return 1;
    else if( a.x == b.x && a.y < b.y )
        return 1;

    return 0;
}
int comp( m a, m b )
{
    if( a.x == b.x && a.y == b.y )
        return 1;

    return 0;
}
int main()
{
    fin >> n;
    fin >> q[1].x >> q[1].y;
    long long v = 1;

    for( int i = 2; i <= n; i++ )
        {
            fin >> a.x >> a.y;
            int ok = 0;

            for( int j = 1; j <= v; j++ )
                if( a.y > q[j].y && inter( a, q[j] ) )
                    {
                        q[j] = a;
                        ok = 1;
                    }
                else if( inter( q[j], a ) )
                    {
                        ok = 1;
                        break;
                    }

            if( ok == 0 )
                {
                    v++;
                    q[v] = a;
                }
        }

    sort( q + 1, q + v + 1, cond );
    n = v;
    int nr = 1;

    for( int i = 1; i < v; i++ )
        if( !comp( q[i], q[i + 1] ) )
            nr++;



    fout << nr;
    return 0;
}
