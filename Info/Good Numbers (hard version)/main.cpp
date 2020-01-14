#include <bits/stdc++.h>
using namespace std;
#define ll long long
int q;
ll x;
ll p3[50];
vector<ll>b3;
int main()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( false );
    cin >> q;

    while( q )
        {
            q--;
            cin >> x;
            b3.clear();

            while( x )
                {
                    b3.push_back( x % 3 );
                    x /= 3;
                }

            b3.push_back( 0 );
            b3.push_back( 0 );
            b3.push_back( 0 );



            for( int i = 0; i < b3.size(); i++ )
                {
                    if( b3[i] == 3 )
                        {
                            b3[i] = 0;
                            b3[i + 1]++;
                        }
                    else if( b3[i] == 2 )
                        {
                            for( int j = 0; j <= i; j++ )
                                b3[j] = 0;

                            b3[i + 1]++;
                        }
                }

            ll sol = 0;
            reverse( b3.begin(), b3.end() );

            for( int i = 0; i < b3.size(); i++ )
                sol = 3 * sol + b3[i];

            cout << sol << '\n';
        }

    return 0;
}
