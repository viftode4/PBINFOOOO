#include <bits/stdc++.h>
using namespace std;
int n, k, nr;
priority_queue<int> q;
set<int>::iterator it;
int main()
{
    cin >> n >> k;
    int cn = n, b = 1;

    while( cn > 0 )
        {
            if( cn % 2 == 1 )
                q.push( b );

            cn = cn / 2;
            b = b * 2;
        }

    if( q.size() > k )
        {
            cout << "NO";
            return 0;
        }

    while( q.size() < k && q.top() != 1 )
        {
            int t = q.top();
            q.pop();
            q.push( t / 2 );
            q.push( t / 2 );
        }

    if( q.size() < k )
        {
            cout << "NO";
            return 0;
        }

    cout << "YES" << endl;;

    while( !q.empty() )
        {
            cout << q.top() << ' ';;
            q.pop();
        }

    return 0;
}
