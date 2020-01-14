#include <bits/stdc++.h>
using namespace std;
int q, str, in, ex;
int main()
{
    cin >> q;
    while( q )
        {
            q--;
            cin >> str >> in >> ex;
            int rez = 0;
            int addint = 0;
            int l = 0, r = ex, ok = -1;

            while( l <= r )
                {
                    int mid = ( l + r + 1 ) / 2;

                    if( in + mid < str + ex - mid )
                        {
                            l = mid + 1;
                            ok = mid;
                        }
                    else
                        r = mid - 1;
                }

            cout << ok + 1 << '\n';

            //cout << rez << '\n';
        }

    return 0;
}
