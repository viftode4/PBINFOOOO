#include <bits/stdc++.h>
using namespace std;
int l1, h1, l2, h2;
int smax;
int main()
{
    cin >> l1 >> h1 >> l2 >> h2;
    //aria pt l1 h1 l2 h2
    int a1 = min( h1, h2 ) * ( l1 + l2 );
    int a2 = min( l1, l2 ) * ( h1 + h2 );
    smax = max( max( a1, a2 ), smax );
    swap( l2, h2 );
    //pt l1 h1 h2 l2
    a1 = min( h1, h2 ) * ( l1 + l2 );
    a2 = min( l1, l2 ) * ( h1 + h2 );
    smax = max( max( a1, a2 ), smax );
    swap( l1, h1 );
    //pt h1 l1 h2 l2
    a1 = min( h1, h2 ) * ( l1 + l2 );
    a2 = min( l1, l2 ) * ( h1 + h2 );
    smax = max( max( a1, a2 ), smax );
    //pt h1 l1 l2 h2
    swap( l2, h2 );
    a1 = min( h1, h2 ) * ( l1 + l2 );
    a2 = min( l1, l2 ) * ( h1 + h2 );
    smax = max( max( a1, a2 ), smax );
    cout << smax;
    return 0;
}
