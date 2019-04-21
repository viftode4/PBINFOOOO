///IFTOEDE VLAD
#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "lrx.in" );
ofstream fout ( "lrx.out" );
int n, ans, nri;
int a[10000], b[10000], dif[10000];
struct diferenta
{
    int v, i;
    bool operator<( const diferenta &a )
    {
        if( a.v != v )
            return a.v > v;

        return a.i > i;
    }
} v[10000];
struct interval
{
    int l, r;
};
vector<interval>m;
int ok( interval x )
{
    return x.l <= x.r;
}
int main()
{
    fin >> n;

    for ( int i = 1; i <= n; i++ )
        fin >> a[i];

    for ( int i = 1; i <= n; i++ )
        fin >> b[i];

    for ( int i = 1; i <= n; i++ )
        {
            dif[i] = b[i] - a[i];
            v[i].i = i;
            v[i].v = dif[i];
        }

    sort( v + 1, v + n + 1 );
    interval x;
    x.l = 1;
    x.r = n;
    m.push_back( x );

    for ( int i = 1; i <= n; i++ )
        {
            int nri = m.size();
            ///aduni la raspuns cate intervale ai pana acum inmultite cu inaltimea de la cel anterior la cel actial
            ans += nri * ( v[i].v - v[i - 1].v );
            int j = i;

            ///scot elementele j egale cu i din intervale
            do
                {
                    int nri = m.size();

                    for( int i = 0; i < nri; i++ )
                        {
                            if( m[i].l <= v[i].i && m[i].r >= v[i].i )
                                {
                                    interval s, d;
                                    //intervalul din stanga
                                    s.l = m[i].l;
                                    s.r = v[i].i - 1;
                                    //intervalul din dreapta
                                    d.l = v[i].i + 1;
                                    d.r = m[i].r;
                                    //sterg intervalul mare
                                    m.erase( m.begin() + i );

                                    //daca s valida
                                    if( ok( s ) )
                                        m.push_back( s );

                                    //daca d valida
                                    if( ok( d ) )
                                        m.push_back( d );
                                }
                        }

                    ///ma opresc cand urmatorul element nu mai e egal cu cel anterior
                    if( v[i].v != v[i + 1].v )
                        break;

                    i++;
                }
            while( true );
        }

    fout << ans;

    return 0;
}
