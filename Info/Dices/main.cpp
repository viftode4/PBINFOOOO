#include <bits/stdc++.h>
using namespace std;
int a, b;
int fr[300], frmax;
int main()
{
    cin >> a >> b;

    for( int i = 1; i <= a; i++ )
        for( int j = 1; j <= b; j++ )
            fr[i + j]++;

    for( int i = 1; i <= 200; i++ )
        frmax = max( frmax, fr[i] );

    for( int i = 1; i <= 200; i++ )
        if( fr[i] == frmax )
            cout << i << '\n';

    return 0;
}
