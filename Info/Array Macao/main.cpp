#include <bits/stdc++.h>
using namespace std;
int n, x;
int va[100010];
int vb[100010];
vector<int> ca[10];
vector<int> cb[10];
vector<int> a[100010];
vector<int> b[100010];
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> va[i];
            int x = va[i];

            while( x )
                {
                    if( ca[x % 10].back() != i )
                        ca[x % 10].push_back( i );

                    x /= 10;
                }
        }

    for( int i = 1; i <= n; i++ )
        {
            cin >> vb[i];
            int x = vb[i];

            while( x )
                {
                    if( cb[x % 10].back() != i )
                        cb[x % 10].push_back( i );

                    x /= 10;
                }
        }

    for( int i = 1; i <= n; i++ )
        {
            int x = va[i];
            int fr[10] = {0};

            while( x )
                {
                    if( fr[x % 10] == 0 )
                        {
                            int pos = caut( b, x % 10, i );

                            for( int j = pos; j <= b[x % 10].size(); j++ )
                                {

                                }
                        }

                    x = x / 10;
                }
        }

    return 0;
}
