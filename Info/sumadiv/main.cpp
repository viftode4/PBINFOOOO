#include <fstream>
using namespace std;
ifstream fin("sumadiv.in");
ofstream fout("sumadiv.out");
int sd(int n, int i) {
    if(i*i==n)
        return i;
    if(i*i>n)
        return 0;
    if(n%i==0)
        return (i+n/i)+sd(n,i+1);
    return sd(n,i+1);
}
int n;
int main() {
    fin>>n;
    fout<<sd(n,1);
    return 0;
}
