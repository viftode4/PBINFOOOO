#include <bits/stdc++.h>
using namespace std;
int n, nrt, st, dr;
int a[300005];
priority_queue<int>q;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            q.push( a[i] );
        }

    int ok = 0;

    while( !q.empty() && !ok )
        {
            ok = 1;
            int a, b;
            a = q.top();
            q.pop();
            b = -1;

            if( !q.empty() )
                {
                    b = q.top();
                    q.pop();
                }

            if( b == -1 && a > 2 )
                {
                    nrt += a / 3;
                    ok = 0;
                }
            cout<<a<<' '<<b<<'\n';
            if( a / 2 > b )
                {
                    a -= b * 2;
                    q.push( a );
                    nrt += b;
                    ok = 0;
                }
            else
                {
                    int t = a / 2;

                    if( t != 0 )
                        ok = 0;

                    a -= t;
                    b -= t;

                    nrt += t;

                    if( a > 0 )
                        q.push( a );

                    if( b > 0 )
                        q.push( b );
                }

        }

    cout << nrt;
    return 0;
}
