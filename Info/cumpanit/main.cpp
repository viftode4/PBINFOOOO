#include <bits/stdc++.h>
using namespace std;
ifstream fin( "cumpanit.in" );
ofstream fout( "cumpanit.out" );
long long x, y;
int b[100];
int e[100];
int ciur[100];
int baza[10], sb[100];
int exp[10];
vector <int>prim;
long long put[50][50];
void era()
{
    ciur[0] = ciur[1] = 1;

    for( int i = 4; i <= 48; i += 2 )
        ciur[i] ++;

    for( int i = 3; i <= 48; i += 2 )
        if( ciur[i] == 0 )
            for( int j = i + i; j <= 48; j += i )
                ciur[j] = 1;

}
void gene( int i )
{
    if( i > 6 )
        return;

    for( int )
    }
void genb( int i )
{
    if( i > 6 )
        return;

    for( auto it : prim )
        {
            if( b[it] == 0 )
                {
                    b[it] = 1;
                    baza[i] = it;
                    sb[i] = sb[i - 1] + it;
                    gene( 1 );
                }
        }
}
int main()
{
    cin >> x >> y;
    era();

    for( int i = 1; i <= 48; i++ )
        if( ciur[i] == 0 )
            prim.push_back( i );

    for( int i = 1; i <= 48; i++ )
        {
            put[i][1] = i;

            for( int j = 2; j <= 48; j++ )
                if( put[i][j - 1] >= 0 )
                    put[i][j] = put[i][j - 1] * i;
        }

    genb( 1 );
    return 0;
}
