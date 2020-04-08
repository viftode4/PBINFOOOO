#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <io.h>

#define     ROWS        50
#define     COLS        80

// The total number of generations is really double this number.
int generations = 1000;

int civ1[ROWS + 2][COLS + 2], civ2[ROWS + 2][COLS + 2];

CHAR_INFO disp[ROWS][COLS];
HANDLE console;
COORD size = { COLS, ROWS };
COORD src = { 0, 0};
SMALL_RECT  dest = { 0, 0, COLS, ROWS };

void ClrScrn ( char attrib )
{
    COORD pos = { 0, 0};
    DWORD written;
    unsigned size;
    size = ROWS * COLS;
    FillConsoleOutputCharacter ( console, ' ', size, pos, &written );
    FillConsoleOutputAttribute ( console, attrib, size, pos, &written );
    SetConsoleCursorPosition ( console, pos );
}

void fill_edges ( int civ1[ROWS + 2][COLS + 2] )
{
    int i, j;

    for ( i = 1; i <= ROWS; ++i )
        {
            civ1[i][0] = civ1[i][COLS];
            civ1[i][COLS + 1] = civ1[i][1];
        }

    for ( j = 1; j <= COLS; ++j )
        {
            civ1[0][j] = civ1[ROWS][j];
            civ1[ROWS + 1][j] = civ1[1][j];
        }

    civ1[0][0] = civ1[ROWS][COLS];
    civ1[ROWS + 1][COLS + 1] = civ1[1][1];
    civ1[0][COLS + 1] = civ1[ROWS][1];
    civ1[ROWS + 1][0] = civ1[1][COLS];
}

void update_generation ( int old_gen[ROWS + 2][COLS + 2],
                         int new_gen[ROWS + 2][COLS + 2] )
{
    int i, j, count;

    for ( i = 1; i <= ROWS; ++i )
        {
            for ( j = 1; j <= COLS; ++j )
                {
                    count = old_gen[i - 1][j - 1] +
                            old_gen[i - 1][j] +
                            old_gen[i - 1][j + 1] +
                            old_gen[i][j - 1] +
                            old_gen[i][j + 1] +
                            old_gen[i + 1][j - 1] +
                            old_gen[i + 1][j] +
                            old_gen[i + 1][j + 1];

                    switch ( count )
                        {
                        case 2:
                            new_gen[i][j] = old_gen[i][j];
                            break;

                        case 3:
                            new_gen[i][j] = 1;
                            disp[i - 1][j - 1].Char.AsciiChar = '*';
                            break;

                        default:
                            new_gen[i][j] = 0;
                            disp[i - 1][j - 1].Char.AsciiChar = ' ';
                            break;
                        }
                }
        }

    WriteConsoleOutput ( console, ( CHAR_INFO * ) disp, size, src, &dest );
    fill_edges ( new_gen );
}

void initialize ( void )
{
    int i, j;
    ClrScrn ( 0x71 );
    srand ( ( ( unsigned int ) time ( NULL ) ) | 1 );

    for ( i = 1; i <= ROWS; ++i )
        {
            for ( j = 1; j <= COLS; ++j )
                {
                    civ1[i][j] = ( int ) ( ( ( __int64 ) rand() * 2 ) / RAND_MAX );
                    disp[i - 1][j - 1].Char.AsciiChar = civ1[i][j] ? '*' : ' ';
                    disp[i - 1][j - 1].Attributes = 0x71;
                }
        }

    WriteConsoleOutput ( console, ( CHAR_INFO * ) disp, size, src, &dest );
    fill_edges ( civ1 );
}

int main ( int argc, char **argv )
{
    int i;

    if ( argc != 1 )
        generations = atoi ( argv[1] );

    console = GetStdHandle ( STD_OUTPUT_HANDLE );
    initialize();

    for ( i = 0; i < generations; ++i )
        {
            update_generation ( civ1, civ2 );
            update_generation ( civ2, civ1 );
        }

    return EXIT_SUCCESS;
}
