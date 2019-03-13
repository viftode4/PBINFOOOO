#include <fstream>
using namespace std;
ifstream fin("munte1.in");
ofstream fout("munte1.out");
int n, a[701][701], x;
int main()
{
   fin>>n;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    fin>>a[i][j];
   fin>>x;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(a[i][j]==x)
   {
       fout<<i<<' '<<j;
       return 0;
   }
    return 0;
}
