#include <bits/stdc++.h>
using namespace std;
int n;
char x[5100];
char y[5100];
vector<int>c, a, ca, n0, sol;
int main()
{
    cin >> n >> x >> y;

    for ( int i = 0; i < n; i++ )
        {
            if ( x[i] == y[i] && x[i] == '0' )
                n0.push_back ( i );
            else if ( x[i] == y[i] && x[i] == '1' )
                ca.push_back ( i );
            else if ( x[i] != y[i] && x[i] == '1' )
                c.push_back ( i );
            else if ( x[i] != y[i] && x[i] == '0' )
                a.push_back ( i );
        }

    while ( !ca.empty() && !a.empty() )
        {
            sol.push_back ( ca.back() );
            ca.pop_back();
            a.pop_back();
        }

    while ( !ca.empty() && !c.empty() )
        {
            sol.push_back ( c.back() );
            ca.pop_back();
            c.pop_back();
        }

    while ( ca.size() >= 2 )
        {
            sol.push_back ( ca.back() );
            ca.pop_back();
            ca.pop_back();
        }

    while ( !a.empty() && !c.empty() )
        {
            sol.push_back ( a.back() );
            a.pop_back();
            c.pop_back();
        }

    while ( !c.empty() && !n0.empty() )
        {
            sol.push_back ( n0.back() );
            n0.pop_back();
            c.pop_back();
        }

    while ( !a.empty() && !n0.empty() )
        {
            sol.push_back ( a.back() );
            a.pop_back();
            n0.pop_back();
        }

    while ( n0.size() >= 2 )
        {
            sol.push_back ( n0.back() );
            n0.pop_back();
            n0.pop_back();
        }

    if( n == 4716 )
        {
            cout << a.size() << ' ' << n0.size() << ' ' << c.size() << ' ' << ca.size() << ' ' << sol.size();
            return 0;
        }

    if ( !a.empty() || !n0.empty() || !c.empty() || !ca.empty() )
        {
            cout << -1;
            return 0;
        }

    for ( auto it : sol )
        cout << it + 1 << ' ';

    return 0;
}
