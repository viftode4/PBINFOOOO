#include <bits/stdc++.h>
using namespace std;
string a;
int n, v, ok = 1;
char s[200005];
int main()
{
    cin >> n;
    cin >> a;
    v = 0;
    s[v] = a[0];
    int i = 1;

    while( a[i] == s[v] )
        i++;

    for( i; i < n; i++ )
        {
            s[++v] = a[i];

            if( a[i + 1] == a[i] && ok == 1 )
                s[++v] = a[i];
            else if( a[i + 1] != a[i] )
                ok = 1 - ok;

            while( a[i] == a[i + 1] )
                i++;
        }

    v -= ( v + 1 ) % 2;
    s[v + 1] = NULL;
    cout << n - v - 1 << '\n';
    cout << s;
    //for( int i )
    return 0;
}
