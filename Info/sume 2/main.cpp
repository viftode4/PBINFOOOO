#include <fstream>
using namespace std;
ifstream fin("sume2.in");
ofstream fout("sume2.out");
int n, x, y;
long long s[100001];
int main() {
    fin>>n;
    for(int i=1; i<=n; i++) {
        fin>>x;
        s[i]=s[i-1]+x;
    }
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>x>>y;
        fout<<s[y]-s[x-1]<<endl;
    }
        return 0;
}
