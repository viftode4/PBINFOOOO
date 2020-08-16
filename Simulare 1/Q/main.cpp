#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin ( "xxx.in" );
ofstream fout ( "xxx.in" );
void fast()
{
    cin.tie ( 0 );
    ios_base::sync_with_stdio ( 0 );
}
char s[120];
int main()
{
    fast();
    cin.getline ( s, 100, '\n' );

    while ( s[0] == ' ' )
        {
            strcpy ( s, s + 1 );
        }

    int plus = 0;

    if ( s[0] == '+' )
        {
            plus = 1;
            strcpy ( s, s + 1 );
        }

    while ( s[0] == '0' && ( strlen ( s ) > 1 && s[1] != '.' ) )
        {
            strcpy ( s, s + 1 );
        }

    int pct = 0, poz = -1;

    for ( int i = 0; s[i]; i++ )
        {
            if ( s[i] == '.' )
                {
                    pct = 1;
                    poz = i;
                    break;
                }
            else if ( ! ( s[i] >= '0' && s[i] <= '9' ) )
                {
                    cout << "invalid input";
                    return 0;
                }
        }

    if ( poz != -1 )
        {
            for ( int i = poz + 1; s[i]; i++ )
                if ( s[i] != '0' )
                    {
                        cout << "invalid input";
                        return 0;
                    }

            if ( !s[poz + 1] )
                {
                    cout << "invalid input";
                    return 0;
                }

            s[poz] = NULL;
        }

    if ( strlen ( s ) > 0 )
        cout << s;
    else
        {
            if ( poz == 0 )
                cout << 0;
            else
                cout << "invalid input";
        }

    return 0;
}
