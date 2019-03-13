#include <iostream>
using namespace std;
int n;
string s;
int fr[300];
int nrt, p, nr;
int main()
{
    cin >> n;
    cin >> s;
    p = 0;
    nr = 0;

    for( int i = 0; i < n; i++ )
        {

            fr[s[i]]++;
            nr++;
            while( fr[s[i]] > 1 )
                {
                    nr--;
                    nrt += nr;
                    fr[s[p]]--;
                    p++;
                }

        }

    while( p <= n )
        {
            nrt += nr;
            nr--;
            p++;
        }

    cout << nrt;
    return 0;
}
