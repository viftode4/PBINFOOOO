#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
int n, x, sol;
int a[110], nr[3];
vector <int>v[3];
int main()
{
    cin >> n;
    nr[0] = n / 2;
    nr[1] = n / 2 + n % 2;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            a[i] = x;

            if( x )
                {
                    if( x % 2 )
                        nr[1]--;
                    else
                        nr[0]--;
                }
        }

    if( a[1] == 0 )
        {
            int i;

            for( i = 1; i < n + 2; i++ )
                if( a[i + 1] )
                    break;

            if( i > nr[a[0] % 2] )
                sol --;
        }

    if( a[n] == 0 )
        {
            int i;

            for( i = 1; i < n + 2; i++ )
                if( a[n - i] )
                    break;

            if( i > nr[a[n + 1] % 2] )
                sol --;
        }

    int lg = 0;
    int ant = 0;

    for( int i = 1; i <= n + 1; i++ )
        {
            if( a[i] && a[i - 1] && ( a[i - 1] % 2 != a[i] % 2 ) )
                sol++;

            if( i == n + 1 )
                a[i] = ant;

            if( !a[i] )
                lg++;

            if( a[i] && lg )
                {
                    if( a[0] == 0 )
                        a[0] = a[i], ant = a[0];

                    if( ant % 2 == a[i] % 2 )
                        v[ant % 2].pb( lg );
                    else
                        v[2].pb( lg );

                    lg = 0;
                    ant = a[i];
                }
        }

    sort( all( v[0] ) );
    sort( all( v[1] ) );
    sort( all( v[2] ) );
    //
//    for( auto it : v[0] )
//        cout << it << ' ';
//
//    cout << '\n';
//
//    for( auto it : v[1] )
//        cout << it << ' ';
//
//    cout << '\n';
//
//    for( auto it : v[2] )
//        cout << it << ' ';
//
//    cout << '\n';
    n = v[0].size();

    for( auto it : v[0] )
        if( nr[0] >= it )
            {
                n--;
                nr[0] -= it;
            }

    sol += 2 * n;
    n = v[1].size();

    for( auto it : v[1] )
        if( nr[1] >= it )
            {
                n--;
                nr[1] -= it;
            }

    sol += 2 * n;
    sol += v[2].size();
    cout << sol;
    return 0;
}
