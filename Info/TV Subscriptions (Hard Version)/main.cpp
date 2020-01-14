#include <bits/stdc++.h>
using namespace std;
int q, n, k, d, x;
int main()
{
    ios_base::sync_with_stdio( false );
    cin.tie( 0 );
    cin >> q;

    while( q )
        {
            q--;
           // cout << "--------------------\n";
            cin >> n >> k >> d;
            map<int, int>m;
            queue<int>q;
            set<int> s;

            for( int i = 1; i <= d; i++ )
                {
                    cin >> x;
                    q.push( x );
                    m[x]++;

                    if( m[x] == 1 )
                        s.insert( x );
                }

            int sol = s.size();

            for( int i = d + 1; i <= n; i++ )
                {
                    cin >> x;
                   // cout << x << '\n';
                    m[x]++;

                    if( m[x] == 1 )
                        s.insert( x );

                    q.push( x );
                    int a = q.front();
                    q.pop();
                    m[a]--;

                    if( m[a] == 0 )
                        s.erase( a );


                    int l = s.size();
                    sol = min( sol, l );
//                    cout << sol << '\n';
//                    cout << "SET:";
//
//                    for( auto it : s     )
//                        cout << it << ' ' << m[it] << '\n';
//
//                    cout << endl;
                }

            cout << sol << '\n';
        }

    return 0;
}
