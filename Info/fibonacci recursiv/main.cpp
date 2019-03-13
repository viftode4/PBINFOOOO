#include <bits/stdc++.h>
using namespace std;
ifstream fin("fibonaci.in");
ofstream fout("fibonaci.out");
void fib(int a, int b, int n) {
    if(a+b>n)
        exit(0);
    cout<<a+b<<' ';
    fib(b,a+b,n);
}
int n, a,b;
int main() {
    cin>>a>>b>>n;
    if(n==1)
        cout<<a;
    else if(n>=2) {
        cout<<a<<' '<<b<<' ';
        fib(a, b, n);
    }
    return 0;
}
