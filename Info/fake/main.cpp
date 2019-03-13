#include <bits/stdc++.h>
using namespace std;
int a, b;
int main()
{
    cin >> a >> b;

    for( int i = a; i < b; i += 2 )
            cout << i << ' ' << i + 1 << '\n';


    return 0;
}
