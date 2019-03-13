#include <fstream>
using namespace std;
ifstream fin("nrapprime.in");
ofstream fout("nrapprime.out");
int n, x, d, i, ok, nr;
int main() {
    fin>>n;
    for(i=1; i<=n; i++) {
        fin>>x;
        ok=1;
        if(x%2==0&&x!=2||x==0||x==1)
            ok=0;
        for(d=3; d*d<=x; d=d+2)
            if(x%d==0) {
                ok=0;
                break;
            }
        if(ok==1)
            nr++;
    }
    fout<<nr;
    return 0;
}
