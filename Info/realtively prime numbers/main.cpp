#include <iostream>
using namespace std;
#define fin cin
#define fout cout
long long a,b;
int main() {
    fin>>a>>b;
    if((a-b+1)%2==0) {
        fout<<"YES"<<'\n';
        for(long long i=a; i<=b; i+=2)
            fout<<i<<' '<<i+1<<'\n';
    } else
        fout<<"NO";

    return 0;
}
