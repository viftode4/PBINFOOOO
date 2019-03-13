#include <iostream>
using namespace std;
#define fin cin
#define fout cout
int dp[100];
int n, k;
int main() {
    fin>>k>>n;
    dp[1]=k-1;
    dp[2]=k*(k-1);
    for(int i=3; i<=n; i++)
        dp[i]=dp[i-1]*(k-1)+dp[i-2]*(k-1);
    fout<<dp[n];
    return 0;
}
