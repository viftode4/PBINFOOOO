#include <iostream>
using namespace std;
char c;
int n, x, L[101], R[101], nr;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>c;
        if(c=='R')
            R[x]++;
        else L[x]++;
    }
    for(int i=1;i<=100;i++)
    {
        if(R[i]>0&&L[i]>0)
            nr=nr+min(R[i],L[i]);
    }
    cout<<nr;
    return 0;
}
