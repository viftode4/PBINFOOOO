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
ll q;
ll n, m, a, b, g;
ll s1, s2, e1, e2;
int main()
{
    fast();
    cin >> n >> m >> q;
    g = __gcd( n, m );
    a = n / g;
    b = m / g;

    for( int i = 1; i <= q; i++ )
        {
            cin >> s1 >> s2 >> e1 >> e2;
            s2--;
            e2--;
            ll grup1 = 0, grup2 = 0;

            if( s1 == 1 )
                grup1 = s2 / a;
            else
                grup1 = s2 / b;

            if( e1 == 1 )
                grup2 = e2 / a;
            else
                grup2 = e2 / b;

            cout << ( ( grup1 == grup2 ) ? "YES\n" : "NO\n" );
        }

    return 0;
}
