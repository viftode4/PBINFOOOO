#include <bits/stdc++.h>
using namespace std;
int n, cat, nr8;
string s;
int main()
{
    cin >> n >> s;
    cat = n - 11;

    for( int i = 0; i <= cat; i++ )
        if( s[i] == '8' )
            nr8++;

    if( nr8 > cat / 2 )
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
