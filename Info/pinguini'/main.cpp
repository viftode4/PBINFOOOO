#include <fstream>
using namespace std;
ifstream fin("pinguini.in");
ofstream fout("pinguini.out");
int c, n, x, lg, lgmax, nr, i, y;
int main() {
    fin>>c>>n;
    if(c==1) {
        nr=0;
        for(i=1; i<=n; i++) {
            fin>>x;
            if(x==2)
                nr++;
        }
        fout<<nr;
    } else {
        fin>>x;
        if(x==2)
            lg=1;
        for(i=1; i<=n-1; i++) {
            fin>>y;
            if(x==y&&x==2)
                lg++;
            else if(x!=y&&x==2) {
                if(lg>lgmax)
                    lgmax=lg;
                lg=0;
                nr++;
            }
            x=y;
        }
        if(x==2)
            nr++;
        if(lg>lgmax)
            lgmax=lg;
        if(c==2)
            fout<<nr;
        else
            fout<<lgmax+1;
    }
    return 0;
}
