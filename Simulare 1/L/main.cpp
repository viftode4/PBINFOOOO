#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "xxx.in" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
bool inters ( int l1x, int l1y, int r1x, int r1y, int l2x, int l2y, int r2x, int r2y )
{
    if ( l1x > r2x || l2x > r1x )
        return false;

    if ( l1y < r2y || l2y < r1y )
        return false;

    return true;
}
bool interior ( int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22 )
{
    if ( x11 <= x21 && y11 >= y21 && x12 >= x22 && y12 <= y22 )
        return 1;

    return 0;
}
int n;
int main()
{
    fast();
    cin >> n;

    while ( n-- )
        {
            int x11, x12, y11, y12;
            int x21, x22, y21, y22;
            cin >> x11 >> y11 >> x12 >> y12;

            if ( x11 > x12 )
                swap ( x11, x12 );

            if ( y11 < y12 )
                swap ( y11, y12 );

            cin >> x21 >> y21 >> x22 >> y22;

            if ( x21 > x22 )
                swap ( x21, x22 );

            if ( y21 < y22 )
                swap ( y21, y22 );

            cout << 3 + inters ( x11, y11, x12, y12, x21, y21, x22, y22 ) - interior ( x11, y11, x12, y12, x21, y21, x22, y22 ) - interior ( x21, y21, x22, y22, x11, y11, x12, y12 ) << '\n';
        }

    return 0;
}
