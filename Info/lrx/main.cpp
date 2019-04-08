#include <bits/stdc++.h>
using namespace std;
ifstream fin ( "lrx.in" );
ofstream fout ( "lrx.out" );
int n;
int a[10000], b[10000], dif[10000];
int s[10000], v;
struct xx
{
    int l, r, x;
};
vector<xx>sol;
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

            if ( dif[i] < 0 )
                {
                    fout << "NO";
                    return 0;
                }
        }

    int ok = 0;

    for ( int i = 1; i <= n; i++ )
        fout << dif[i] << ' ';

    fout << endl;

    for ( int i = 2; i <= n; i++ )
        if ( dif[i] != dif[i - 1] )
            ok = 1;

    if ( !ok )
        {
            if ( dif[1] == 0 )
                fout << "0";
            else
                fout << 1 << ' ' << n << ' ' << dif[1];

            return 0;
        }


    fout << endl;
    dif[0] = -1;

    for ( int i = 1; i <= n; i++ )
        {
            s[++v] = i;

            while ( dif[s[v]] <= dif[s[v - 1]] )
                {
                    if ( dif[s[v]] == dif[s[v - 1]] )
                        {
                            v--;
                            continue;
                        }

                    xx nr;
                    nr.l = s[v - 1];
                    nr.r = s[v] - 1;
                    nr.x =  abs( dif[s[v]] - dif[s[v - 1]] );
                    sol.push_back ( nr );
                    s[v - 1] = s[v];
                    v--;
                }
        }

    while ( v )
        {
            xx nr;
            nr.l = s[v];
            nr.r = n;
            nr.x = abs( dif[s[v]] - dif[s[v - 1]] );
            sol.push_back ( nr );
            v--;
        }

    fout << sol.size() << '\n';

    for ( auto it : sol )
        fout << it.l << ' ' << it.r << ' ' << it.x << '\n';

    return 0;
}
