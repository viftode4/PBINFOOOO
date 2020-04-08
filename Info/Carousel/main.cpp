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
int c[200005];
int a[200005];
void afisare( int n )
{
    for( int i = 1; i <= n; i++ )
        cout << c[i] << ' ';

    cout << '\n';
}
int main()
{
    fast();
    int t;
    cin >> t;

    while( t-- )
        {
            int n;
            cin >> n;
            cin >> a[1];
            int ant = 1, ok = 0;
            c[1] = 1;

            for( int i = 2; i <= n; i++ )
                {
                    cin >> a[i];

                    if( a[i] != a[i - 1] )
                        {
                            ok = 1;
                            ant = 3 - ant;
                        }

                    c[i] = ant;
                }

            if( ok == 0 )
                {
                    cout << 1 << '\n';
                    afisare( n );
                    continue;
                }

            ok = 0;
            int next = a[2];
            int i = 1;
            ant = c[n];

            for( int i = n; i >= 1 && a[i] == a[1]; i-- )
                ant = c[i - 1];

            for( int i = 2; i <= n && a[i] == a[i - 1]; i++ )
                next = c[i + 1];

            if( next != ant )
                {
                    ok = 1;
                    c[1] = 3;

                    for( int i = 1; i <= n && a[i] == a[i - 1]; i++ )
                        c[i] = 3;

                    for( int i = n; i >= 1 && a[i] == a[1]; i-- )
                        c[i] = 3;
                }

            cout << 2 + ok << '\n';

            afisare( n );

        }

    return 0;
}
