#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
int n, k;
string s;
int  a[N];
int nr[300];
vector<int> v[30];
int main()
{
    cin >> n >> k;
    cin >> s;
    a[0] = 1;

    for( int i = 1; i <= n; i++ )
        {
            if( s[i] != s[i - 1] )
                {
                    a[i] = 1;
                    nr[s[i - 1] - 'a' + 1] += a[i - 1] / k;
                }
            else
                a[i] = a[i - 1] + 1;

            //cout << a[i] << ' ';
        }

    int nrmax = 0;

    for( char i = 'a'; i <= 'z'; i++ )
        nrmax = max( nrmax, nr[i - 'a' + 1] );


    cout << nrmax;
    return 0;
}
