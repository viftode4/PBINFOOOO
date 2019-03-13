#include <iostream>
using namespace std;
#define fin cin
#define fout cout
long long dp[50], n;
int main() {
    fin>>n;
    dp[1]=2;
    dp[2]=2;
    for(int i=3; i<=n; i++)
        dp[i]=dp[i-1]+dp[i-2];
    fout<<dp[n];
    return 0;
}
