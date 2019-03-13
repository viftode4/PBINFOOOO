#include <fstream>
using namespace std;
ifstream fin("furnici.in");
ofstream fout("furnici.out");
int n, x, maxi, b;
char d;
int main()
{
    fin>>b>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>x>>d;
            if(d=='S')
            maxi=max(maxi,x);
            else if(d=='D')
                maxi=max(maxi,b-x+1);
    }
    fout<<maxi;
    return 0;
}
