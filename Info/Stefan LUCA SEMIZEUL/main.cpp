#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("MCMI-IIItest.in");
ofstream fout("MCMI-IIItest.out");
ifstream fin2("tabel_M.in");
int suma1y=0,suma0y=0,suma1z=0,suma2z=0,rezultat;
float suma15=0,suma25=0,suma05=0;
float x=0,a;
int brutX=0;
char raspunsuri[180];
int main() {
    struct Informatii {
        int suma0,suma1,suma2,suma3;
    };

    struct Informatii test1, test2, test3, test4, test5, test6, test7, test8, test9, test10, test11, test12, test13, test14, test15, test16, test17, test18, test19, test20, test21, test22, test23, test24, test25, test26;

    test1.suma0=0;
    test1.suma1=0;
    test2.suma1=0;
    test2.suma2=0;
    test3.suma1=0;
    test4.suma1=0;
    test4.suma2=0;
    test5.suma1=0;
    test5.suma2=0;
    test5.suma0=0;
    test6.suma0=0;
    test6.suma1=0;
    test6.suma2=0;
    test7.suma0=0;
    test7.suma1=0;
    test7.suma2=0;
    test8.suma0=0;
    test8.suma2=0;
    test9.suma1=0;
    test9.suma2=0;
    test10.suma0=0;
    test10.suma1=0;
    test10.suma2=0;
    test11.suma0=0;
    test11.suma1=0;
    test11.suma2=0;
    test12.suma0=0;
    test12.suma2=0;
    test13.suma1=0;
    test13.suma2=0;
    test14.suma1=0;
    test14.suma2=0;
    test15.suma1=0;
    test15.suma2=0;
    test16.suma1=0;
    test16.suma2=0;
    test17.suma1=0;
    test17.suma2=0;
    test18.suma1=0;
    test18.suma2=0;
    test19.suma1=0;
    test19.suma2=0;
    test20.suma1=0;
    test20.suma2=0;
    test21.suma1=0;
    test21.suma2=0;
    test21.suma3=0;
    test22.suma1=0;
    test22.suma2=0;
    test23.suma1=0;
    test23.suma2=0;
    test24.suma1=0;
    test24.suma2=0;
    test25.suma1=0;
    test25.suma2=0;
    test26.suma1=0;
    test26.suma2=0;
    for(int contor=1; contor<=175; contor++) {
        fin>>raspunsuri[contor];
        //Scala Y:
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==20||contor==35||contor==40||contor==69||contor==104||contor==112||contor==148||contor==141||contor==142||contor==123||contor==151))
            test1.suma0++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==32||contor==51||contor==57||contor==59||contor==88||contor==82||contor==80||contor==97||contor==137||contor==172))
            test1.suma1++;
        //Scala Z:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==1||contor==4||contor==8||contor==15||contor==22||contor==24||contor==30||contor==34||contor==36||contor==37||contor==44||contor==55||contor==56||contor==58||contor==62||contor==63||contor==70||contor==74||contor==75||contor==76||contor==83||contor==84||contor==86||contor==99||contor==111||contor==123||contor==128|contor==133||contor==134||contor==142||contor==145||contor==150||contor==171))
            test3.suma1++;
        //Scala 1:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==10||contor==27||contor==46||contor==92||contor==105||contor==148||contor==165))
            test7.suma2+=2;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==4||contor==38||contor==48||contor==101||contor==142||contor==156||contor==167))
            test7.suma1++;
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==32||contor==57))
            test7.suma0++;
        //Scala 2A:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==18||contor==40||contor==69||contor==84||contor==99||contor==127||contor==141||contor==174))
            test5.suma2+=2;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==47||contor==48||contor==146||contor==148||contor==151||contor==158))
            test5.suma1++;
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==57||contor==80))
            test5.suma0++;
        //Scala 2B:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==151||contor==123||contor==133||contor==145||contor==112||contor==47||contor==20||contor==25))
            test4.suma2+=2;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==24||contor==43||contor==83||contor==86||contor==142||contor==148||contor==154))
            test4.suma1++;
        //Scala 3:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==16||contor==35||contor==45||contor==73||contor==94||contor==108||contor==135||contor==169))
            test6.suma2+=2;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==47||contor==56||contor==84||contor==120||contor==133||contor==141||contor==151))
            test6.suma1++;
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==82))
            test6.suma0++;
        //Scala 4:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==12||contor==21||contor==51||contor==57||contor==80||contor==88||contor==32))
            test8.suma2+=2;
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==10||contor==24||contor==27||contor==48||contor==69||contor==92||contor==92||contor==99||contor==123||contor==127||contor==174))
            test8.suma0++;
        //Scala 5:
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==35||contor==40||contor==47||contor==69||contor==84||contor==86||contor==94||contor==99||contor==141||contor==169))
            suma05++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==21||contor==38||contor==57||contor==80||contor==88||contor==116))
            suma15++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==5||contor==26||contor==31||contor==67||contor==85||contor==93||contor==144||contor==159))
            suma25+=2;
        //Scala 6A:
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&contor==172)
            test11.suma0++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==7||contor==13||contor==14||contor==21||contor==41||contor==52||contor==93||contor==122||contor==136))
            test11.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==17||contor==38||contor==53||contor==101||contor==113||contor==139||contor==166))
            test11.suma2+=2;
        //Scala 6B:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==9||contor==14||contor==28||contor==64||contor==87||contor==95||contor==116))
            test9.suma2+=2;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==7||contor==13||contor==17||contor==33||contor==36||contor==39||contor==41||contor==49||contor==53||contor==79||contor==93||contor==96||contor==166))
            test9.suma1++;
        //Scala 7:
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==7||contor==14||contor==22||contor==41||contor==53||contor==72||contor==101||contor==139||contor==166))
            test12.suma0++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==2||contor==29||contor==59||contor==82||contor==97||contor==114||contor==137||contor==172))
            test12.suma2+=2;
        //Scala 8A:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==6||contor==42||contor==83||contor==98||contor==122||contor==133||contor==166))
            test13.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==7||contor==15||contor==22||contor==36||contor==50||contor==60||contor==79||contor==115||contor==126))
            test13.suma2+=2;
        //Scala 8B:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==18||contor==24||contor==25||contor==35||contor==40||contor==98||contor==148||contor==169))
            test2.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==19||contor==43||contor==70||contor==90||contor==104||contor==122||contor==161))
            test2.suma2+=2;
        //Scala S:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==69||contor==99||contor==102||contor==134||contor==141||contor==148||contor==151))
            test14.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==8||contor==48||contor==71||contor==76||contor==117||contor==138||contor==156||contor==158||contor==162))
            test14.suma2+=2;
        //Scala C:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==7||contor==22||contor==122||contor==135||contor==161||contor==166||contor==171))
            test15.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==30||contor==41||contor==72||contor==83||contor==98||contor==120||contor==134||contor==142||contor==154))
            test15.suma2+=2;
        //Scala P:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==8||contor==48||contor==60||contor==63||contor==115||contor==138||contor==158||contor==159))
            test16.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==6||contor==33||contor==42||contor==49||contor==89||contor==103||contor==146||contor==167||contor==175))
            test16.suma2+=2;
        //Scala A:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==40||contor==61||contor==76||contor==108||contor==109||contor==135||contor==145||contor==149))
            test17.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==58||contor==75||contor==124||contor==147||contor==164||contor==170))
            test17.suma2+=2;
        //Scala H:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==1||contor==75||contor==107||contor==111||contor==130||contor==145||contor==148))
            test18.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==4||contor==11||contor==37||contor==55||contor==74))
            test18.suma2+=2;
        //Scala N:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==22||contor==41||contor==51||contor==83||contor==117||contor==134||contor==166||contor==170))
            test19.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==3||contor==54||contor==96||contor==106||contor==125))
            test19.suma2+=2;
        //Scala D:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==15||contor==25||contor==55||contor==83||contor==104||contor==141||contor==142||contor==148))
            test20.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==24||contor==56||contor==62||contor==86||contor==111||contor==130))
            test20.suma2+=2;
        //Scala B:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==14||contor==41||contor==64||contor==93||contor==101||contor==113||contor==122||contor==139||contor==166))
            test21.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==52||contor==77||contor==100||contor==131||contor==152))
            test21.suma2+=2;
        if((raspunsuri[contor]=='f'||raspunsuri[contor]=='F')&&(contor==23))
            test21.suma3+=2;
        //Scala T:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==7||contor==21||contor==38||contor==41||contor==53||contor==101||contor==113||contor==139))
            test22.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==13||contor==39||contor==66||contor==91||contor==118||contor==136))
            test22.suma2+=2;
        //Scala R:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==62||contor==767||contor==83||contor==123||contor==133||contor==142||contor==147||contor==148||contor==151||contor==154||contor==164))
            test23.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==109||contor==129||contor==149||contor==160||contor==173))
            test23.suma2+=2;
        //Scala SS:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==22||contor==56||contor==72||contor==76||contor==83||contor==117||contor==134||contor==142||contor==148||contor==151||contor==162))
            test24.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==34||contor==61||contor==68||contor==78||contor==102||contor==168))
            test24.suma2+=2;
        //Scala CC:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==4||contor==34||contor==55||contor==74||contor==104||contor==111||contor==130||contor==142||contor==142||contor==148||contor==149||contor==154))
            test25.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==1||contor==44||contor==107||contor==128||contor==150||contor==171))
            test25.suma2+=2;

        //Scala PP:
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==5||contor==38||contor==49||contor==67||contor==89||contor==103||contor==138||contor==159||contor==175))
            test26.suma1++;
        if((raspunsuri[contor]=='a'||raspunsuri[contor]=='A')&&(contor==63||contor==119||contor==140||contor==153))
            test26.suma2+=2;
        //Scala X:
        x=0.6667*(suma05+suma15+suma25);
        a=x-int(x);
        if(a<0.5)
            x=int(x);
        else
            x=int(x+1);
        brutX=(test7.suma0+test7.suma1+test7.suma2)+(test5.suma1+test5.suma2+test5.suma0)+(test4.suma1+test4.suma2)+(test6.suma0+test6.suma1+test6.suma2)+(test8.suma0+test8.suma2)+(test11.suma0+test11.suma1+test11.suma2)+(test9.suma1+test9.suma2)+(test12.suma0+test12.suma2)+(test13.suma1+test13.suma2)+(test2.suma1+test2.suma2)+x;
    }
    fout<<"Scala X="<<brutX<<endl;
    fout<<"Scala Y="<<test1.suma1+test1.suma0<<endl;
    fout<<"Scala Z="<<test3.suma1<<endl;
    fout<<"Scala 1="<<test7.suma0+test7.suma1+test7.suma2<<endl;
    fout<<"Scala 2A="<<test5.suma1+test5.suma2+test5.suma0<<endl;
    fout<<"Scala 2B="<<test4.suma1+test4.suma2<<endl;
    fout<<"Scala 3="<<test6.suma0+test6.suma1+test6.suma2<<endl;
    fout<<"Scala 4="<<test8.suma0+test8.suma2<<endl;
    fout<<"Scala 5="<<suma05+suma15+suma25<<endl;
    fout<<"Scala 6A="<<test11.suma0+test11.suma1+test11.suma2<<endl;
    fout<<"Scala 6B="<<test9.suma1+test9.suma2<<endl;
    fout<<"Scala 7="<<test12.suma0+test12.suma2<<endl;
    fout<<"Scala 8A="<<test13.suma1+test13.suma2<<endl;
    fout<<"Scala 8B="<<test2.suma1+test2.suma2<<endl;
    fout<<"Scala S="<<test14.suma1+test14.suma2<<endl;
    fout<<"Scala C="<<test15.suma1+test15.suma2<<endl;
    fout<<"Scala P="<<test16.suma1+test16.suma2<<endl;
    fout<<"Scala A="<<test17.suma1+test17.suma2<<endl;
    fout<<"Scala H="<<test18.suma1+test18.suma2<<endl;
    fout<<"Scala N="<<test19.suma1+test19.suma2<<endl;
    fout<<"Scala D="<<test20.suma1+test20.suma2<<endl;
    fout<<"Scala B="<<test21.suma1+test21.suma2+test21.suma3<<endl;
    fout<<"Scala T="<<test22.suma1+test22.suma2<<endl;
    fout<<"Scala R="<<test23.suma1+test23.suma2<<endl;
    fout<<"Scala SS="<<test24.suma1+test24.suma2<<endl;
    fout<<"Scala CC="<<test25.suma1+test25.suma2<<endl;
    fout<<"Scala PP="<<test26.suma1+test26.suma2<<endl;
    int s[50];
    s[25]=test1.suma1+test1.suma0;
    s[26]=test3.suma1;
    s[1]=test7.suma0+test7.suma1+test7.suma2;
    s[2]=test5.suma1+test5.suma2+test5.suma0;
    s[3]=test4.suma1+test4.suma2;
    s[4]=test6.suma0+test6.suma1+test6.suma2;
    s[5]=test8.suma0+test8.suma2;
    s[6]=suma05+suma15+suma25;
    s[7]=test11.suma0+test11.suma1+test11.suma2;
    s[8]=test9.suma1+test9.suma2;
    s[9]=test12.suma0+test12.suma2;
    s[10]=test13.suma1+test13.suma2;
    s[11]=test2.suma1+test2.suma2;
    s[12]=test14.suma1+test14.suma2;
    s[13]=test15.suma1+test15.suma2;
    s[14]=test16.suma1+test16.suma2;
    s[15]=test17.suma1+test17.suma2;
    s[16]=test18.suma1+test18.suma2;
    s[17]=test19.suma1+test19.suma2;
    s[18]=test20.suma1+test20.suma2;
    s[19]=test21.suma1+test21.suma2+test21.suma3;
    s[20]=test22.suma1+test22.suma2;
    s[21]=test23.suma1+test23.suma2;
    s[22]=test24.suma1+test24.suma2;
    s[23]=test25.suma1+test25.suma2;
    s[24]=test26.suma1+test26.suma2;
    int m[100][100],i,j;
    for(i=1; i<=34; i++) {
        for(j=1; j<=26; j++) {
            fin2>>m[i][j];
        }
    }
    for(int i=1; i<=26; i++) {
        fout<<endl;
        for(int j=1; j<=26; j++)
            fout<<m[s[i]+1][j]<<' ';
    }
    return 0;
}
