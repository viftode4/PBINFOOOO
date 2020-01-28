#include <bits/stdc++.h>
using namespace std;
int n, k, sol;
string s;
set<string>x;
queue<string> q;
int main()
{
    cin >> n >> k >> s;
    q.push( s );
    x.insert( s );

    while( x.size() < k && !q.empty() )
        {
            string v = q.front();
            q.pop();

            for( int i = 0; i < v.size(); i++ )
                {
                    string cv = v;
                    cv.erase( i, 1 );

                    if( !x.count( cv ) && x.size() + 1 <= k )
                        {
                            q.push( cv );
                            x.insert( cv );
                            sol += n - cv.size();
                        }
                }
        }

    if( x.size() != k )
        cout << -1;
    else
        cout << sol;

    return 0;
}
