#include <bits/stdc++.h>
using namespace std;
string s;
int hexadecimalToDecimal( string hexVal )
{
    long long len = hexVal.size();

    // Initializing base value to 1, i.e 16^0
    long long base = 1;

    long long dec_val = 0;

    // Extracting characters as digits from last character
    for ( int i = len - 1; i >= 0; i-- )
        {
            // if character lies in '0'-'9', converting
            // it to integral 0-9 by subtracting 48 from
            // ASCII value.
            if ( hexVal[i] >= '0' && hexVal[i] <= '9' )
                {
                    dec_val += ( hexVal[i] - 48LL ) * base;

                    // incrementing base by power
                    base = base * 16LL;
                }

            // if character lies in 'A'-'F' , converting
            // it to integral 10 - 15 by subtracting 55
            // from ASCII value
            else if ( hexVal[i] >= 'A' && hexVal[i] <= 'F' )
                {
                    dec_val += ( hexVal[i] - 55LL ) * base;

                    // incrementing base by power
                    base = base * 16LL;
                }
        }

    return dec_val;
}
int main()
{
    cin >> s;
    long long n = hexadecimalToDecimal( s );
    cout << n % 2;
    return 0;
}
