#include <iostream>
#include "draw.h"
using namespace std;
void drawScreen ( char screen[100][100], int screen_h, int screen_w )
{
    for ( int i = 0; i < screen_h; i++ )
        {
            for ( int j = 0; j < screen_w; j++ )
                cout << screen[i][j];

            cout <<'\n';
        }

    cout<<flush;
}
