#include <bits/stdc++.h>
using namespace std;
ifstream fin( "expresie7.in" );
ofstream fout( "expresie7.out" );
string s;
stack <string> q;
int a[100010], n, nrnr = 0;
void trans()
{
    n = 0;

    while( q.top() != "(" && q.top() != "[" )
        {
            int nr = 0, semn = 1;
            string c = q.top();
            nrnr++;
            nr = stoi( c );
            a[++n] = nr;
            q.pop();
        }
}
void rezp()
{
    trans();
    nth_element( a + 1, a + ( n + 1 ) / 2, a + n + 1 );
    string s = to_string( a[n / 2] );
    q.push( s );
}
void rezr()
{
    trans();
    int s = -1e9, m = 1e9;

    for( int i = 1; i <= n; i++ )
        {
            a[i] += a[i - 1];
            s = max( s, a[i] - m );
            m = min( a[i], m );
        }

    string c = to_string( s );
    q.push( c );
}
int main()
{
    cin >> s;
    string c = "";

    for( int i = 0; s[i]; i++ )
        {
            if( s[i] == '-' || s[i] <= '9' && s[i] >= '0' )
                c += s[i];
            else if( s[i] == ',' )
                {
                    q.push( c );
                    c = "";
                    nrnr++;
                }
            else
                {
                    if( s[i] == ')' )
                        {
                            nrnr++;
                            rezr();
                        }
                    else if( s[i] == ']' )
                        {
                            nrnr++;
                            rezp();
                        }
                    else
                        {
                            c += s[i];
                            q.push( c );
                            c = "";
                        }
                }
        }

    int s = 0;

    while( !q.empty() )
        {
            int nr = 0;
            string c = q.top();
            nr = stoi( c );
            s = s + nr;
            q.pop();
        }

    cout << nrnr << endl << s;
    return 0;
}
