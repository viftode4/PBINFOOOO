#include <bits/stdc++.h>
using namespace std;
int n, k, x, v[5010];
map<int, int> a;
queue<int> q[5010];
int main()
{
    cin >> n >> k;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            a[x]++;
            q[x].push( i );
        }

    x = 1;

    for( auto it : a )
        {
            if( it.second > k )
                {
                    cout << "NO";
                    return 0;
                }
            else
                {
                    if( x + it.second > k )
                        x = k - it.second + 1;

                    for( int i = 1; i <= it.second; i++ )
                        {
                            v[q[it.first].front()] = x;
                            x++;
                            q[it.first].pop();
                        }
                }
        }

    cout << "YES" << endl;

    for( int i = 1; i <= n; i++ )
        cout << v[i] << ' ';

    return 0;
}
