#include <iostream>
using namespace std;
int n, pos;
string s;
string sol[7] = {"RGB", "RBG", "BRG", "BGR", "GRB", "GBR"};
int nr[7], tmin, nrmin;
int main()
{
    cin >> n;
    cin >> s;

    for( int t = 0; t <= 5; t++ )
        {
            for( int i = 0; i < n; i ++ )
                {
                    if( s[i] != sol[t][i % 3] )
                        nr[t]++;
                }
        }

    nrmin = nr[0];
    tmin = 0;
    for( int i = 1; i <= 5; i++ )
        {
            if( nrmin > nr[i] )
                {
                    nrmin = nr[i];
                    tmin = i;
                }
        }

    cout << nr[tmin] << endl;

    for( int i = 0; i < n; i++ )
        cout << sol[tmin][i % 3];

    return 0;
}
