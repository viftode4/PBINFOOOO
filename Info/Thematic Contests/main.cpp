#include <bits/stdc++.h>
using namespace std;
long long n, x, j, k, nr;
map<long long, int>m;
map<long long, int>::iterator it;
long long a[2000005];
int gasit( long long nr )
{
    int l = j + 1, r = k;

    while( r > l )
        {
            int m = ( l + r ) / 2;

            if( a[m] >= nr )
                r = m;
            else
                l = m + 1;
        }

    if( a[l] < nr )
        return 0;
    else
        {
            j = l;
            //cout << " gasit " << nr << " la poz " << j << ' ';
            return 1;
        }
}
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            m[x]++;
        }

    k = 0;
    n = 0;

    for( it = m.begin(); it != m.end(); it++ )
        {
            a[++k] = it->second;
            n = max( n, a[k] );
        }

    long long nrmax = 0;
    //cout << n << ' ';

    for( int i = 1; i <= n; i++ )
        {
            long long p = i;
            nr = 0;
            j = 0;
            //cout << "pentru " << p << '-';

            while( gasit( p ) )
                {
                    //cout << p << ' ';
                    nr += p;
                    p = p * 2;

                }

            //cout << endl;
            nrmax = max( nrmax, nr );
        }

    cout << nrmax;
    return 0;
}
