#include <bits/stdc++.h>
using namespace std;
#define nd second
#define st first
#define pb push_back
int n, x;
vector<int>a;
int main()
{
    cin >> n;
    map<int, int>m;

    for( int i = 1; i <= n; i++ )
        {
            cin >> x;
            m[x]++;
        }

    for( auto it : m )
        a.pb( it.st );

    for( auto it : a )
        cout << it<<' ';

    return 0;
}
