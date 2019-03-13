#include <bits/stdc++.h>
using namespace std;
int n;
int x;
int fr[10001];
int a[100001];
long long s;
int main()
{
    cin >> n;

    for( int i = 1; i <= n; i++ )
        {
            cin >> a[i];
            fr[a[i]]++;
        }

    for( int i = 1; i < 10000; i++ )
        {
            s += i * i * fr[i] * (fr[i]-1) / 2;
            for( int j = i + 1; j <= 10000;j++ )
                s += i * j * fr[i] * fr[j];
        }
    cout<<s;
    return 0;
}
