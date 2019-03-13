#include <fstream>
using namespace std;
ifstream fin("lipsa.in");
ofstream fout("lipsa.out");
long long n, x, s, i;
int main()
{
    fin>>n;
    for(i=1;i<=n-1;i++)
    {
        fin>>x;
        s=s+x;
    }
    fout<<n*(n+1)/2-s;
    return 0;
}
