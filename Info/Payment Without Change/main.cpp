#include <iostream>

using namespace std;
int q, a, b, n, s;
int main()
{
    cin >> q;

    while( q )
        {
            q--;
            cin >> a >> b >> n >> s;

            int nr = s / n;

            if( nr > a )
                {
                    s -= a * n;

                    if( s <= b )
                        cout << "YES";
                    else
                        cout << "NO";
                }
            else
                {
                    s -= nr * n;

                    if( s <= b )
                        cout << "YES";
                    else
                        cout << "NO";
                }
                cout<<'\n';
        }

    return 0;
}
