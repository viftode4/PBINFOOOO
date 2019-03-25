#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int MOD = 998244353;
ull n, k, x;
ull sum = 1, nr, nrp, cate;
ull fri[300010];
ull frp[300010];
ull fpw( ull baza, ull exp )
{
    ull r = 1;

    if( exp == 0 )
        return 1;

    if( baza == 0 )
        return 0;

    while( exp )
        {
            if( exp % 2 == 1 )
                r = ( baza * r ) % MOD;

            baza = ( baza * baza ) % MOD;
            exp /= 2;
        }

    return r;
}
int main()
{
    cin >> n >> k;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;

            if( x == -1 )
                {
                    nr++;

                    if( i % 2 == 0 )
                        nrp++;
                }
            else
                {


                    if( i % 2 == 0 )
                        frp[x]++;
                    else
                        fri[x]++;
                }
        }

    sum = 1;

    for( int i = 1; i <= k; i++ )
        if( fri[i] == 0 )
            cate++;

    for( int i = 1; i <= nr - nrp; i++ )
        {
            sum = ( sum * cate ) % MOD;
            cate--;
        }

    cate = 0;

    for( int i = 1; i <= k; i++ )
        if( frp[i] == 0 )
            cate++;
    //cout<<nrp<<' '<<nr<<' ';
    for( int i = 1; i <= nrp; i++ )
        {
            sum = ( sum * cate ) % MOD;
            cate--;
        }

    cout << sum << '\n';;
    //cout << sum << '\n';
    return 0;
}
