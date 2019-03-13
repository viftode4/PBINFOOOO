#include <bits/stdc++.h>
using namespace std;
int n;
int a[16], b[16];
void rez()
{
    int x = 0;

    for( int i = 1; i <= n; i++ )
        if( b[i] == 0 )
            x = x + a[i];
        else
            x = x - a[i];

    if( x % 360 == 0 )
        {
            cout << "YES";
            exit( 0 );
        }
}
void generare( int k )
{
    for( int i = k; i <= n; i++ )
        {
            b[i] = 1;
            rez();
            generare( i + 1 );
            b[i] = 0;
        }
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        cin >> a[i];

    generare( 1 );
    cout << "NO";
    return 0;
}
