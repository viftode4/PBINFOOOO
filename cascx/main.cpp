#include <iostream>
using namespace std;
int n, v[1001], i, max1, max2;
int main()
{
    cin >> n;
    i = 1;

    while ( i <= n )
        {
            cin >> v[i];    // citim numerele
            i++;
        }

    // initializam maximele cu primele 2 numere din sir
    // max1 este maximul
    // max2 este al doilea cel mai mare
    max1 = v[1];
    max2 = v[2];

    if ( v[1] >= v[2] )
        {
            max1 = v[1];
            max2 = v[2];
        }
    else
        {
            max1 = v[2];
            max2 = v[1];
        }

    //incepem de la al treilea numar
    i = 3;

    while ( i <= n )
        {
            if ( v[i] > max1 ) // verificam daca elementul curent
                // este mai mare decat maximul
                {
                    max2 = max1; //cel mai mare de pana acum devine
                    //al doilea cel mai mare
                    max1 = v[i]; //cel mai mare devin el curent
                }
            // daca nu, verificam daca e mai mare
            // decat al doilea cel mai mare
            else if ( v[i] > max2 )
                max2 = v[i];

            i++;
        }

    cout << max1 << ' ' << max2;
    return 0;
}
