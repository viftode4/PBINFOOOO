#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("fantastice.in");
ofstream fout("fantastice.out");
int n, x, nr,ciur[1000008];
int main() {
    for ( int i = 3; i * i <= 1000000; i+=2 ) {
        if ( ciur[i] == 0 ) {
            for ( int j = i; j <= 1000000 / i; j++ )
                ciur[i * j] = 1;
        }
    }
    fin>>n;
    for(int i=1; i<=n; i++) {
        fin>>x;
        int nrd=0;
        for(int d=1; d<=sqrt(x); d++)
            if(x%d==0)
                nrd+=2;
        if(x==sqrt(x)*sqrt(x))
            nrd--;
        if(ciur[x]==0&&x%2!=0||ciur[nrd]==0&&nrd%2!=0||x==2||nrd==2)
            nr++;
    }
    fout<<nr;
    return 0;
}
