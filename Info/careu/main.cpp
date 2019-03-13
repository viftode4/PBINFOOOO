#include <fstream>
using namespace std;
ifstream fin("careu.in");
ofstream fout("careu.out");
int n;
char a[51][51];
int main() {
    fin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            fin>>a[i][j];

    return 0;
}
