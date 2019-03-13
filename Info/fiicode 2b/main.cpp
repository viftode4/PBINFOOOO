#include <bits/stdc++.h>
using namespace std;
ifstream fin("test.in");
int n, m;
int a[300001];
int v[300001];
int c[300001];
struct pos
{
    int s, d;
} b[300001];
int main()
{
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= n; i++ )
        {
            v[a[i]] = v[a[i] + m] = i;
            b[i].s = a[i];
            b[i].d = a[i] + m;
        }

    for( int i = 1; i <= 2 * m; i++ )
        if( v[i] == 0 )
            c[i] = c[i - 1] + 1;
        else
            c[i] = c[i - 1];

    /* for( int i = 1; i <= 2 * m; i++ )
         cout << v[i] << ' ';

     cout << endl;

     for( int i = 1; i <= 2 * m; i++ )
         cout << c[i] << ' ';
    */
    int l = 2, r = 1, smin = c[b[n].s] - c[b[1].s - 1], s = 0;

    do
        {
            s = c[b[r].d] - c[b[l].s - 1];
            smin = min( smin, s );
            l++;
            r++;
        }
    while( l != n + 1 );

//   cout << endl;
    cout << smin;
    return 0;
}
