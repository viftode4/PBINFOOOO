#include <bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
ifstream fin( "xxx.in" );
ofstream fout( "xxx.in" );
void fast()
{
    cin.tie( 0 );
    ios_base::sync_with_stdio( 0 );
}
int t;
string s;
int dp[5010][5010];
int main()
{
    fast();
    cin >> t;

    while( t-- )
        {
            cin >> s;
            int n = s.size();
            string a, b, c, sol;

            for( int i = 0; i <= n / 2; i++ )
                {
                    a = "";
                    b = "";
                    c = "";
                    int l = i - 1, r = i + 1;
                    b = s[i];

                    while( l >= 0 && r < n && s[l] == s[r] )
                        {
                            b = b + s[r];
                            b = s[l] + b;
                            l--;
                            r++;
                        }

                    int st = 0, dr = n - 1;

                    while( st <= l && s[st] == s[dr] )
                        {
                            a = a + s[st];
                            c = s[dr] + c;
                            st++;
                            dr--;
                        }

                    string aux = a + b + c;

                    if( st - 1 == l && aux.size() > sol.size() )
                        sol = a + b + c;

                    if( s[i] == s[i + 1] && i + 1 <= n / 2 )
                        {
                            a = "";
                            b = "";
                            c = "";
                            int l = i - 1, r = i + 2;
                            b += s[i];
                            b += s[i + 1];

                            while( l >= 0 && r < n && s[l] == s[r] )
                                {
                                    b = b + s[r];
                                    b = s[l] + b;
                                    l--;
                                    r++;
                                }

                            int st = 0, dr = n - 1;

                            while( st <= l && s[st] == s[dr] )
                                {
                                    a = a + s[st];
                                    c = s[dr] + c;
                                    st++;
                                    dr--;
                                }

                            string aux = a + b + c;

                            if( st - 1 == l && aux.size() > sol.size() )
                                sol = a + b + c;
                        }
                }

            reverse( s.begin(), s.end() );

            for( int i = 0; i <= n / 2; i++ )
                {
                    a = "";
                    b = "";
                    c = "";
                    int l = i - 1, r = i + 1;
                    b = s[i];

                    while( l >= 0 && r < n && s[l] == s[r] )
                        {
                            b = b + s[r];
                            b = s[l] + b;
                            l--;
                            r++;
                        }

                    int st = 0, dr = n - 1;

                    while( st <= l && s[st] == s[dr] )
                        {
                            a = a + s[st];
                            c = s[dr] + c;
                            st++;
                            dr--;
                        }

                    string aux = a + b + c;

                    if( st - 1 == l && aux.size() > sol.size() )
                        sol = a + b + c;

                    if( s[i] == s[i + 1] && i + 1 <= n / 2 )
                        {
                            a = "";
                            b = "";
                            c = "";
                            int l = i - 1, r = i + 2;
                            b += s[i];
                            b += s[i + 1];

                            while( l >= 0 && r < n && s[l] == s[r] )
                                {
                                    b = b + s[r];
                                    b = s[l] + b;
                                    l--;
                                    r++;
                                }

                            int st = 0, dr = n - 1;

                            while( st <= l && s[st] == s[dr] )
                                {
                                    a = a + s[st];
                                    c = s[dr] + c;
                                    st++;
                                    dr--;
                                }

                            string aux = a + b + c;

                            if( st - 1 == l && aux.size() > sol.size() )
                                sol = a + b + c;
                        }
                }


            cout << sol << '\n';

        }

    return 0;
}
