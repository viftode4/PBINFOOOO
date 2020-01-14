#include <bits/stdc++.h>
using namespace std;
int n, nra, nrb;
string a, b;
queue<int> qa, qb;
int sola[200005], solb[200005], v;
int main()
{
    cin >> n;
    cin >> a >> b;

    for( int i = 0; i < n; i++ )
        if( a[i] == 'a' && a[i] != b[i] )
            {
                nra++;
                qa.push( i + 1 );
            }
        else if( a[i] == 'b' && a[i] != b[i] )
            {
                nrb++;
                qb.push( i + 1 );
            }

    if( ( qa.size() + qb.size() ) % 2 == 1 )
        {
            cout << -1;
            return 0;
        }

    while( !qa.empty() )
        {
            if( qa.size() % 2 == 1 )
                {
                    v++;
                    sola[v] = qa.front();
                    solb[v] = qa.front();
                    qb.push( qa.front() );
                    qa.pop();
                }
            else
                {
                    int x = qa.front();
                    qa.pop();
                    int y = qa.front();
                    qa.pop();
                    v++;
                    sola[v] = x;
                    solb[v] = y;
                }
        }

    while( !qb.empty() )
        {
            int x = qb.front();
            qb.pop();
            int y = qb.front();
            qb.pop();
            v++;
            sola[v] = x;
            solb[v] = y;
        }

    cout << v << '\n';

    for( int i = 1; i <= v; i++ )
        cout << sola[i] << ' ' << solb[i] << '\n';

    return 0;
}
