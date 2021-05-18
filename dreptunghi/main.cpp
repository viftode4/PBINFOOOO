#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define ll long long
#define pb push_back
#define mp make_pair
void fast()
{
    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 );
}
char s[355];
int p, sol, i = 0;
int cx = 1000, cy = 1000;
void rec ( int x, int y )
{
    cx = min ( cx, x );
    cy = min ( cy, y );

    if ( s[i] == 'H' )
        {
            int c = s[i + 1] - '0';
            i += 2;
            rec ( c, y );
            rec ( x - c, y );
        }
    else if ( s[i] == 'V' )
        {
            int c = s[i + 1] - '0';
            i += 2;
            rec ( x, c );
            rec ( x, y - c );
        }
    else
        {
            i++;
            return;
        }
}
int main()
{
    fast();
    cin >> p;
    cin >> s;

    for ( int i = 0; s[i]; i++ )
        if ( s[i] == 'V' || s[i] == 'H' )
            sol++;

    if ( p == 1 )
        cout << sol + 1;

    if ( p == 2 )
        {
            i = 0;
            rec ( 0, 0 );
            cout << abs ( cx ) + 1 << ' ' << abs ( cy ) + 1;
        }

    return 0;
}
