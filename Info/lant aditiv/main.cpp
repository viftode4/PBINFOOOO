#include <fstream>
using namespace std;
ifstream fin("lantaditiv.in");ofstream fout("lantaditiv.out");
long long n, v[200];
int main() {
    fin>>n;
    int k=0;
    v[++k]=n;
    while(n!=1) {
        if(n%2==1) {
            v[++k]=n/2+1;
        }
        v[++k]=n/2;
        n=n/2;
    }
    fout<<k<<'\n';
    for(int i=1; i<=k; i++)
        fout<<v[k-i+1]<<' ';
    return 0;
}
