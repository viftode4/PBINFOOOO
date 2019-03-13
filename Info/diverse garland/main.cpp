#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map <int, char> a;
map <int, char> b;
int main()
{
    cin >> n;
    a[1] = 'R';
    a[2] = 'G';
    a[3] = 'B';
    b['R'] = 1;
    b['G'] = 2;
    b['B'] = 3;
    cin >> s;
    int nr = 0;

    for( int i = 1; i < n - 1; i ++ )
        {
            if( s[i] == s[i - 1] || s[i] == s[i + 1] )
                {
                    //cout << s[i] << ' ';

                    if( s[i - 1] != s[i + 1] )
                        s[i] = a[6 - ( b[s[i + 1]] + b[s[i - 1]] )];
                    else
                        s[i] = a[( b[s[i + 1]] + 1 ) % 3];

                    //cout << s[i] << ' ';
                    nr++;
                }
        }

    cout << nr << endl;
    cout << s;
    return 0;
}
