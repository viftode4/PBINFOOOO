#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> a[300009];
int main()
{
    cin >> n >> k;

    for( int i = 1; i <= n; ++i )
        cin >> a[i].second >> a[i].first;

    sort( a + 1, a + n + 1 );
    long long res = 0;
    long long sum = 0;
    set<pair<int, int> > s;

    for( int i = n; i >= 1; --i )
        {
            s.insert( make_pair( a[i].second, i ) );
            sum += a[i].second;

            while( s.size() > k )
                {
                    auto it = s.begin();
                    sum -= it->first;
                    s.erase( it );
                }

            res = max( res, sum * a[i].first );
        }

    cout << res << endl;
    return 0;
}
