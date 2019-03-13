#include <fstream>
using namespace std;
ifstream fin( "ecuatii.in" );
ofstream fout( "ecuatii.out" );
struct ec
{
    int r, i;
} a[3];
int n, l;
string s;
int main()
{
    int n;
    fin >> n;

    for( int i = 1; i <= n; i++ )
        {
            fin >> s;
            l = 1;

            for( int i = 0; s[i]; i++ )
                {
                    int nr = 0, m = 1;

                    if( s[i] == '-' )
                        {
                            m = -1;

                            if( nr > 0 )
                                {
                                    a[l].r += a[l].r + nr * m;
                                    nr = 0;
                                    m = 1;
                                }
                        }
                    else if( s[i] > '0' && s[i] < '9' )
                        {
                            nr = nr * 10 + s[i] - '0';
                        }
                    else if( s[i] == 'x' )
                        {
                            a[l].i = a[l].i + nr * m;
                            nr = 0;
                            m = 1;
                        }
                    else if( s[i] == '=' )
                        {
                            l = 2;

                            if( nr > 0 )
                                {
                                    a[l].r += a[l].r + nr * m;
                                    nr = 0;
                                    m = 1;
                                }
                        }
                }

            fout << a[1].i << 'x' << ' ' << a[1].r << " =" << a[2].i << 'x' << a[2].r << endl;;
        }

    return 0;
}
