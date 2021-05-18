#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ( "bac.txt" );
int x, y, z;
int main()
{
    fin >> x >> y;

    while ( fin >> z )
        {
            if ( z > x )
                {
                    cout << z << ' ';
                    break;
                }
            else cout << x << ' ';

            x = y;
            y = z;
        }

    while ( fin >> x )
        cout << x << ' ';

    return 0;
}
