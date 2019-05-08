#include <bits/stdc++.h>
using namespace std;
struct elev
{
    int s, i;
};
bool operator<( const elev&a, const elev&b )
{
    return b.s < a.s;
}
struct lista
{
    int v, p, u;
} a[200005];
set<elev> s;
int n, k, sol[200005], cine;
int main()
{
    cin >> n >> k;
    a[1].p = 0;
    a[n].u = 0;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i].v;
            a[i].u = i + 1;
            a[i].p = i - 1;
            elev x;
            x.s = a[i].v;
            x.i = i;
            s.insert( x );
        }

    while( !s.empty() )
        {
            cine = 1 - cine;
            auto it = s.begin();
            int unde = it->i;
            sol[unde] = cine;
            a[a[unde].p].u = a[unde].u;
            a[a[unde].u].p = a[unde].p;
            s.erase( it );
            int ck = k;

            while( k && a[unde].u != 0 )
                {
                    unde = a[unde].u;
                    sol[unde] = cine;
                    elev x;
                    x.i = unde;
                    x.s = a[unde].v;
                    a[a[unde].p].u = a[unde].u;
                    a[a[unde].u].p = a[unde].p;
                    auto it = s.find( x );

                    if( it != s.end() )
                        s.erase( it );

                    k--;
                }

            k = ck;

            while( k && a[unde].p != 0 )
                {
                    unde = a[unde].p;
                    sol[unde] = cine;
                    elev x;
                    x.i = unde;
                    x.s = a[unde].v;
                    a[a[unde].p].u = a[unde].u;
                    a[a[unde].u].p = a[unde].p;
                    auto it = s.find( x );

                    if( it != s.end() )
                        s.erase( it );

                    k--;
                }

            k = ck;
        }

    for( int i = 1; i <= n; i++ )
        if( sol[i] == 1 )
            cout << sol[i];
        else
            cout << 2;

    return 0;
}
