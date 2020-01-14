#include <bits/stdc++.h>
using namespace std;
ifstream fin( "jbb.in" );
ofstream fout( "jbb.out" );
int n, sa, sb, t, v, s;
int cost[10005];
int to[10005];
vector<int> cicluri[10005];
struct ss
{
    int s1, s2;
} sum[10005];
bool operator<( ss a, ss b )
{
    int xa = a.s1 - a.s2, xb = b.s1 - b.s2;
    return xa > xb;
}
void suma( vector<int> a )
{
    int lg = a.size();
    int sa = 0, sb = 0, p = 0;

    if( lg % 2 == 0 )
        {
            for( auto it : a )
                {
                    p = 1 - p;

                    if( p )
                        sa += cost[it];
                    else
                        sb += cost[it];
                }

            s += max( sa, sb );
            return;
        }

    int samax = 0;

    for( int i = 0; i < lg; i++ )
        {
            sa = sb = 0;
            int j = ( i + 1 ) % lg, p = 1;
            sb = cost[a[i]];

            while( j != i )
                {
                    if( p )
                        sa += cost[a[j]];
                    else
                        sb += cost[a[j]];

                    p = 1 - p;
                    j = ( j + 1 ) % lg;
                }

            samax = max( {sa, sb, samax} );
        }

    sum[++t].s1 = samax;
    sum[t].s2 = sa + sb - samax;
}
int main()
{
    fin >> n;

    for( int i = 1; i <= n; i++ )
        fin >> cost[i];

    for( int i = 1; i <= n; i++ )
        fin >> to[i];

    for( int i = 1; i <= n; i++ )
        if( to[i] )
            {
                v++;
                int x = i;

                while( to[x] )
                    {
                        cicluri[v].push_back( x );
                        int aux = to[x];
                        to[x] = 0;
                        x = aux;
                    }
            }

    for( int i = 1 ; i <= v; i++ )
        suma( cicluri[i] );

    sort( sum + 1, sum + t + 1 );

    /*
    for( int i = 1; i <= t; i++ )
        {
            fout << sum[i].s1 << ' ' << sum[i].s2 << endl;
        }
    */
    for( int i = 1; i <= t; i++ )
        if( i % 2 == 1 )
            s += sum[i].s1;
        else
            s += sum[i].s2;

    fout << s;
    return 0;
}
