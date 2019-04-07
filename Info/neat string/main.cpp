#include <bits/stdc++.h>
using namespace std;
char c[] = {'Q', 'R', 'U', 'O', 'P', 'S', 'D', 'G', 'J', 'C', 'B'};
string s;
int main()
{
    cin >> s;
    int nr=0;

    for( int i = 0; s[i]; i++ )
        for( int j = 0; c[j]; j++ )
            if( s[i] == c[j] )
            {
                nr++;
            }
    // cout<<nr<<' '<<s.size()<<'\n';
    if(nr==0 || nr==s.size())
        cout<<"YES";
    else
        cout << "NO";
    return 0;
}
