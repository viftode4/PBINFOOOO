#include <bits/stdc++.h>
using namespace std;
long long q, n, x, y, a, b, k;
long long p[200005];
int main()
{
    cin >> q;

    while( q-- )
        {
            cin >> n;

            for( int i = 1; i <= n; i++ )
                cin >> p[i];

            cin >> x >> a >> y >> b >> k;
            sort( p + 1, p + n + 1 );
            long long catea = n / a;
            long long cateb = n / b;
            long long comun = a * b / __gcd( a, b );
            long long catecomun = n / comun;
            catea -= catecomun;
            cateb -= catecomun;
            long long sum = 0, bilete = 0;
            //cout << comun << ' ' << catecomun << ' ';

            while( catecomun-- )
                {
                    sum += ( x + y ) * ( p[n] / 100 );
                    bilete++;
                    n--;

                    if( sum >= k )
                        {
                            cout << bilete << '\n';
                            continue;
                        }
                }

            long long suma = 0, bila = 0;
            long long sumb = 0, bilb = 0;

            for( int i = n; i >= n - catea + 1 && sum + suma < k; i-- )
                {
                    suma += p[i] / 100 * x;
                    bila++;
                }

            for( int i = n - catea; i >= n - catea - cateb + 1 && suma + sum < k; i-- )
                {
                    suma += p[i] / 100 * y;
                    bila++;
                }

            for( int i = n; i >= n - cateb + 1 && sum + sumb < k; i-- )
                {
                    sumb += p[i] / 100 * y;
                    bilb ++;
                }

            for( int i = n - catea; i >= n - catea - cateb + 1 && sum + sumb < k; i-- )
                {
                    sumb += p[i] / 100 * x;
                    bilb++;
                }

            if( suma + sum >= k && sumb + sum >= k )
                cout << bilete + min( bilb, bila ) << '\n';
            else if( suma + sum < k && sumb + sum >= k )
                cout << bilete + bilb << '\n';
            else if( suma + sum >= k && sumb + sum <k )
                cout << bilete + bila << '\n';
            else
                cout << -1 << '\n';
        }

    return 0;
}
