#pragma once
#include <Windows.h>
#include <iostream>
#include "shapes.h"
#include "draw.h"
using namespace std;
char screen[100][100];
int screen_h = 20;
int screen_w = 100;
int x;
void gameLoop()
{
    while ( 1 )
        {
            system ( "cls" );
            drawScreen ( screen, screen_h, screen_w );
            //Sleep ( 10 );
            //qDraw.push()
            //cin >> x;
        }
}
int main()
{
    memset ( screen, '#', sizeof screen );
    gameLoop();
    return 0;
}
