#include <fstream>
using namespace std;
ifstream fin("restmare.in");
ofstream fout("restmare.out");\
long long n;
int main()
{
    fin>>n;
    fout<<(long long)(n/2-1)*(n/2)+(n%2)*n/2;
    return 0;
}
