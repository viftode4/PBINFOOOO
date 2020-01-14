#include <iostream>

using namespace std;
int n, a[110];
int poz[110];
void afisare()
{

    for( int i = 1; i <= n; i++ )
        cout << a[i] << ' ';

    cout << '\n';
}
int main()
{
    int q;
    cin >> q;
    //q = 1;

    while( q )
        {
            q--;
            cin >> n;

            for( int i = 1; i <= n; i++ )
                {
                    cin >> a[i];
                    poz[a[i]] = i;
                }

            int nro = n - 1;
            int p = 1;

            for( int i = 1; i <= n && nro; i++ )
                {
                    int minn = i;
                    p = 1;

                    for( int j = i + 1; j <= n; j++ )
                        if( a[j] < a[minn] )
                            minn = j;

                    for( int j = minn; j >= i + 1 && nro; j-- )
                        {
                            p = 0;
                            swap( a[j], a[j - 1] );
                            nro--;
                        }

                    i = minn - 1 + p;
                }

            afisare();
        }

    return 0;
}
