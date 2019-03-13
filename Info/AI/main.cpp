#include <bits/stdc++.h>
using namespace std;
ifstream fin( "ai.in" );
ofstream fout( "ai.out" );
int n, k, x, y;
int a[1010][1010];
struct p
{
    int x, y;
} t, s1, s2, r1, r2, d1[1010], d2[1010];
int main()
{
    cin >> n;
    cin >> t.x >> t.y >> s1.x >> s1.y;
    cin >> s2.x >> s2.y >> r1.x >> r1.y;
    cin >> r2.x >> r2.y;
    cin >> k;

    for( int i = 1; i <= k; i++ )
        {
            cin >> x >> y;
            a[x][y] = 1;
        }

    if( t.x > s1.x )
        {
        }

    return 0;
}
