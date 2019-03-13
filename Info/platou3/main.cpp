#include <fstream>
using namespace std;
ifstream fin("platou3.in");
ofstream fout("platou3.out");
int n, x, lg, lgmax, i;
int main() {
    fin>>n;
    lg=0;
    for(i=1; i<=n; i++) {
        fin>>x;
        if(x>0)
            lg++;
        else {
            if(lg>lgmax)
                lgmax=lg;
            lg=0;
        }
    }
    if(lg>lgmax)
        lgmax=lg;
    fout<<lgmax;
    return 0;
}
