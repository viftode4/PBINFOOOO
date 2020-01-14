#include <bits/stdc++.h>
using namespace std;
ifstream fin( "cerc3.in" );
ofstream fout( "cerc3.out" );
int n, nrd;
int dp[2020];
int sol, nr;
struct cerc
{
    int x, y, r;
} a[2020];
struct dreapta
{
    int x, y;
    vector<int>v;
} d[2020];
int cond( int x, int y )
{
    if( a[x].x == a[y].x )
        {
            if( a[x].y == a[y].y )
                return a[x].r < a[y].r;
            else
                return a[x].y < a[y].y;
        }
    else
        return a[x].x < a[y].x;
}
int dist( int x, int y )
{
    double di =  sqrt( ( a[x].x - a[y].x ) * ( a[x].x - a[y].x ) * 1.0 + ( a[x].y - a[y].y ) * ( a[x].y - a[y].y ) * 1.0 );

    if( di <= a[x].r + a[y].r )
        return 0;

    return 1;
}
int v = 0;
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            int x, y, r;
            fin >> x >> y >> r;
            a[i].x = x;
            a[i].y = y;
            a[i].r = r;
            int g = __gcd( x, y );
            int j;

            for( j = 1; j <= v; j++ )
                if( d[j].x == x / g && d[j].y == y / g )
                    {
                        d[j].v.push_back( i );
                        break;
                    }

            if( j > v )
                {
                    v++;
                    d[v].x = x / g;
                    d[v].y = y / g;
                    d[v].v.push_back( i );
                }
        }

    fout << v << ' ';

    for( int k = 1; k <= v; k++ )
        {
            sort( d[k].v.begin(), d[k].v.end(), cond );
            int n = d[k].v.size();
            vector<int> b = d[k].v;
            int mx = 1;

            for( int i = 0; i <= n; i++ )
                dp[i] = 0;

            dp[0] = 1;

            for( int i = 1; i < n; i++ )
                for( int j = 0; j < i; j++ )
                    {
                        dp[i] = max( dp[i], dp[j] + dist( b[i], b[j] )  );
                        mx = max( mx, dp[i] );
                    }

            if( mx > sol )
                {
                    sol = mx;
                    nr = 1;
                }
            else if( mx == sol )
                nr++;
        }

    fout << sol << ' ' << nr;
    return 0;
}
