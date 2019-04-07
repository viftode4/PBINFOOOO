#include <bits/stdc++.h>
using namespace std;
string s[] = {"P", "R", "S"};
int main()
{
    srand ( time( NULL ) );

    for ( int i = 0; i < 20; ++i )
        {
            cout << s[( rand() % 3 )] << endl;
            cout.flush();
            string verdict;
            getline( cin, verdict );
        }
}
