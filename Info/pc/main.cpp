#include <fstream>
using namespace std;
ifstream fin("pc.in");
ofstream fout("pc.out");
int n, x;
int main() {
    fin>>n;
    for(int i=1; i<=n; i++) {
        fin>>x;
        if(x%2==0)
            fout<<0<<' ';
        else
            fout<<1<<' ';
    }
    return 0;
}
