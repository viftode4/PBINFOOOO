#include <iostream>
using namespace std;
#define fin cin
#define fout cout
int n, r;
int main() {
    fin>>n;
    if(n%3==0)
        fout<<"1 1 "<< n-2;
    else if(n%3==1)
        fout<<"1 1 "<<n-2;
    else if(n%3==2)
        fout<<"1 2 "<<n-3;
    return 0;
}
