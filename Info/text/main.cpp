#include <bits/stdc++.h>
using namespace std;
ifstream fin( "text.in" );
ofstream fout( "text.out" );
string s[20010], sol[20010];
int n, best[20010], p[20010], nm, pos;
int u[20010];
int main()
{
    while( fin >> s[++n] )
        continue;

    n--;

    for( int i = 1; i <= n; i++ )
        {
            best[s[i].back()] = best[s[i].front()] + 1;
            p[i] = u[s[i].front()];
            u[s[i].back()] = i;
        }

    for( int i = n; i >= 1; i-- )
        if( nm < best[s[i].back()] )
            {
                pos = i;
                nm = best[s[i].back()];
            }

    fout << n << endl << n - nm << endl;

    /* for( int i = 1; i <= n; i++ )
         cout << p[i] << ' ';

     cout << endl;*/

    /* for( int i = 1; i <= nm; i++ )
         {
             cout << pos << ' ';
             fout << s[pos];
             pos = p[pos];

         }
    */

    for( int i = 1; i <= nm; i++ )
        {
            sol[nm - i + 1] = s[pos];
            pos = p[pos];
        }

    for( int i = 1; i <= nm; i++ )
        fout << sol[i] << '\n';

    return 0;
}
