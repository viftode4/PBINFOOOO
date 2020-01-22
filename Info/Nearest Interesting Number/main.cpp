#include <bits/stdc++.h>
using namespace std;
int n;
int sumcif( int n )
{
    if( n == 0 )
        return 0;

    return n % 10 + sumcif( n / 10 );
}
int main()
{
    cin >> n;

    for( int i = n;; i++ )
        {
            if( sumcif( i ) % 4 == 0 )
                {
                    cout << i;
                    return 0;
                }
        }

    return 0;
}
