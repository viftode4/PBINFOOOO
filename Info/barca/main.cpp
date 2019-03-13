#include <fstream>
using namespace std;
ifstream fin("barca.in");
ofstream fout("barca.out");
int n;
int main()
{
    fin>>n;
    fout<<n*4<<'\n';
    for(int i=1;i<=n;i++)
        fout<<"IG"<<'\n'<<'I'<<'\n'<<i<<'\n'<<'G'<<'\n';

    return 0;
}
