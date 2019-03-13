#include <fstream>
using namespace std;
ifstream fin("rica.in");
ofstream fout("rica.out");
long long x1, x2, x3, n, s;
int main() {
    fin>>n;
    x1=1;
    x2=1;
    x3=2;
    if(n==1)
        fout<<x1;
    else if(n==2)
        fout<<x2;
    else if(n==3)
        fout<<x3;
    for(int i=4;i<=n;i++)
    {
        s=x1+x2+x3;
        x1=x2;
        x2=x3;
        x3=s;
    }
    fout<<s;
    return 0;
}
