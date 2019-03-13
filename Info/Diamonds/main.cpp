#include <bits/stdc++.h>
using namespace std;
string a, b;
map<char, int>fa, fb;
int main()
{
    cin >> a >> b;

    for( int i = 0; a[i]; i++ )
        fa[a[i]]++;

    for( int i = 0; b[i]; i++ )
        fb[b[i]]++;

    for( int i = 0; a[i]; i++ )
        if( fa[a[i]] != fb[a[i]] )
            {
                cout << "different";
                return 0;
            }

    cout << "equal";

    return 0;
}
