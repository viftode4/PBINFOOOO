#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, x, m, s;
int v[100009], use[1000009];
vector<int> a[1000009], l;
int stop( int n )
{
    int p = 1;

    for( auto it : a[n] )
        if( !use[it] )
            {
                p = 0;
                break;
            }

    return p;
}
int gen( int k )
{
    if( !stop( k ) )
        for( auto it : a[k] )
            {
                if( use[it] == 0 )
                    {
                        use[it] = 1;
                        cout << v[it] << ' ';
                        s++;
                        s = s % MOD;
                        gen( k + 1 );
                        cout << endl;
                        use[it] = 0;
                    }
            }
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> v[i];
            m = max( v[i], m );
        }

    for( int i = 1; i <= m; i++ )
        {
            for( int j = 1; j <= n; j++ )
                if( v[j] % i == 0 )
                    a[i].push_back( j );
        }

    /*for( int i = 1; i <= m; i++ )
        {
            cout << "PT DIV:" << i << endl;

            for( auto it : a[i] )
                cout << it << ' ';

            cout << endl;
        }

    s = 0;*/
    gen( 1 );
    cout << "RASPUNS:" << s;
    return 0;
}
