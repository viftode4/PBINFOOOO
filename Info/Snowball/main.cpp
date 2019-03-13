#include <bits/stdc++.h>
using namespace std;
int h, w, h1, w1, h2, w2;
int a[1000];
int main()
{
    cin >> w >> h;
    cin >> w1 >> h1;
    cin >> w2 >> h2;
    a[h1] = w1;
    a[h2] = w2;

    int s = w;

    for( int i = h; i >= 0; i-- )
        {
            s = s + i;
            s = max( s - a[i], 0 );
        }
    cout<<s;
    return 0;
}
