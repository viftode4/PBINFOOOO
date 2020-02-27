#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
ll a[10005], sol, pos, maxi, x;
ll aux[10005], solv[10005];
int main()
{
    fast();
    ll n;
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];

            if( maxi < a[i] )
                {
                    maxi = a[i];
                    pos = i;
                }
        }

    for( int i = pos; i <= pos; i++ )
        {
            for( int j = 1; j <= n; j++ )
                aux[j] = 0;

            x = 0;
            aux[i] = a[i];

            for( int j = i + 1; j <= n; j++ )
                {
                    if( a[j] >= aux[j - 1] )
                        aux[j] = aux[j - 1];
                    else
                        aux[j] = a[j];
                }

            for( int j = i - 1; j >= 1; j-- )
                {
                    if( a[j] >= aux[j + 1] )
                        aux[j] = aux[j + 1];
                    else
                        aux[j] = a[j];
                }

            for( int j = 1; j <= n; j++ )
                x += aux[j];

            if( sol < x )
                {
                    for( int j = 1; j <= n; j++ )
                        solv[j] = aux[j];

                    sol = x;
                }
        }

    for( int i = 1; i <= n; i++ )
        cout << solv[i] << ' ';

    return 0;
}
