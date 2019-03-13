#include <fstream>
using namespace std;
ifstream fin("skyline.in");
ofstream fout("skyline.out");
struct bloc {
    int h,l;
} a[40005];
struct q {
    int h, i;
} q[40005];
int n, lgmax, k, l;
int main() {
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>a[i].h>>a[i].l;
    q[1].i=q[1].h=0;
    k=1, l=0;
    for(int i=1; i<=n; i++) {
        if(q[k].h<a[i].h) {
            //adaug in coada daca elem curent a este mai mare decat ultimul din coada
            k++;
            q[k].h=a[i].h;
            q[k].i=i;
        } else {
            l=0;
            while(q[k].h>a[i].h) {
                l+=a[q[k].i].l;
                // ti minte lg de la ultimul adaugat pana la asta actual pe care il scot
                //lungimea pana la stanga
                int lg=0;
                while(a[q[k].i-1].h>a[q[k].i].h)
                    lg+=a[q[k].i-1].l;
                //lungimea in dreapta pana la primul mai mic decat cel pe care il scot
                if((lg+l)*q[k].h>lgmax)
                    lgmax=(lg+l)*q[k].h;
                //aria
                k--;
            }
        }
    }
    fout<<lgmax;
    return 0;
}
