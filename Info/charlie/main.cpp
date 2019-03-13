#include <bits/stdc++.h>
using namespace std;
ifstream fin( "charlie.in" );
ofstream fout( "charlie.out" );
string s;
int cer;
int a[100100], v;
char q[100100];
int main()
{
    fin >> cer >> s;

    if( cer == 1 )
        {
            int lg = 0, lgmax = 0, n = s.size();

            for( int i = 1; i < n - 1; i++ )
                if( s[i] < s[i - 1] && s[i] < s[i + 1] )
                    a[i] = 1, a[i - 1] = 1, a[i + 1] = 1;

            for( int i = 0; i <= n; i++ )
                {
                    fout << a[i] << endl;

                    if( a[i] == 1 )
                        lg++;
                    else
                        {
                            lgmax = max( lgmax, lg );
                            lg = 0;
                        }
                }

            fout << lgmax;
        }
    else
        {
            int sum = 0;
            v = 0;

            for( int i = 0; s[i]; i++ )
                {
                    q[++v] = s[i];

                    while( q[v - 1] < q[v] && q[v - 1] < q[v - 2] && v >= 3 )
                        {
                            sum += max( q[v], q[v - 2] ) - 'a' + 1;
                            q[v - 1] = q[v];
                            v--;
                        }
                }

            for( int i = 1; i <= v; i++ )
                fout << q[i];

            fout << endl;
            fout << sum;
        }

    return 0;
}
