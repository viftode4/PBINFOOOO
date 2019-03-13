#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[5];
int s1, s2;
set<pair<int, int>> q;
set<pair<int, int>>::iterator it;
int main()
{
    for( int i = 1; i <= 3; i++ )
        cin >> a[i].first >> a[i].second;

    sort( a + 1, a + 4 );

    for( int i = a[1].second; i <= a[2].second; i++ )
        q.insert( make_pair( a[1].first, i ) );

    for( int i = a[1].first; i <= a[2].first; i++ )
        q.insert( make_pair( i, a[2].second ) );

    for( int i = a[2].second; i <= a[3].second; i++ )
        q.insert( make_pair( a[2].first, i ) );

    for( int i = a[2].first; i <= a[3].first; i++ )
        q.insert( make_pair( i, a[3].second ) );

    cout << q.size() << endl;;

    for( it = q.begin(); it != q.end(); it++ )
        cout << it->first << ' ' << it->second << '\n';

    return 0;
}
