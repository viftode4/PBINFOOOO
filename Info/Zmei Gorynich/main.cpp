#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin >> q;

    while( q )
        {
            q--;
            cin >> n >> x;
            int d, h;
            int scazut = -1e9, fatala = 0;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> d >> h;
                    int delta = d - h;

                    fatala = max( fatala, d );
                    scazut = max( scazut, delta );
                }

            if( scazut <= 0 && fatala < x )
                {
                    cout << "-1\n";
                    continue;
                }

            int hp = x - fatala;

            if( hp <= 0 )
                {
                    cout << "1\n";
                    continue;
                }

            cout << ( hp + scazut - 1 ) / scazut + 1 << '\n';
        }

    return 0;
}
