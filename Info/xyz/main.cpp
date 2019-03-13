#include <fstream>
using namespace std;
ifstream fin("xyz.in");
ofstream fout("xyz.out");
int x,y,z;
int main() {
    fin>>x>>y>>z;
    fout<<y;
    while(x!=1)
    {
        x--;
        fout<<z;
    }
    return 0;
}
