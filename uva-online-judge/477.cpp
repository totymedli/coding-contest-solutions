/*PROBLEM SEMI-SOLVED - Unknown problem in a (should be) correct implementation*/
#include <iostream>
#include <algorithm>

using namespace std;

class alakzat
{
    public:
    double pont[2];
    //Leszarmazottakban lenne.
    double pont2[2];
    double sugar;
};

struct pont
{
    double x,y;
};

/*class teglalap:alakzat
{
    public:
    long pont2[2];
};

class kor:alakzat
{
    public:
    long sugar;
};*/

int main()
{
    alakzat alakok[10];
    char alakok_tipus[10];
    int alakok_szam = 0;
    double be1, be2, be3, be4;
    char betu;

    cin >> betu;
    while (betu!='*')
    {
        if (betu=='r')
        {
            cin >> be1 >> be2 >> be3 >> be4;
            //alakok[alakok_szam] = new teglalap;
            alakok[alakok_szam].pont[0] = be1;
            alakok[alakok_szam].pont[1] = be2;
            alakok[alakok_szam].pont2[0] = be3;
            alakok[alakok_szam].pont2[1] = be4;
            alakok_tipus[alakok_szam] = 'r';
            alakok_szam++;
        }
        else if (betu=='c')
        {
            cin >> be1 >> be2 >> be3;
            //alakok[alakok_szam] = new kor;
            alakok[alakok_szam].pont[0] = be1;
            alakok[alakok_szam].pont[1] = be2;
            alakok[alakok_szam].sugar = be3;
            alakok_tipus[alakok_szam] = 'c';
            alakok_szam++;
        }
        cin >> betu;
    }
    pont pontok[130000];
    int pont_db = 0;
    bool nemvolt = true;
    cin >> pontok[pont_db].x >> pontok[pont_db].y;
    while ((pontok[pont_db].x!=9999.9)&&(pontok[pont_db].y!=9999.9))
    {
        pont_db++;
        cin >> pontok[pont_db].x >> pontok[pont_db].y;
    }
    for (int n=0; n<pont_db; n++)
    {
        for (int j=0; j<alakok_szam; j++)
            {
                if ((alakok_tipus[j]=='r')&&(pontok[n].x>alakok[j].pont[0])&&(pontok[n].x<alakok[j].pont2[0])&&(pontok[n].y>alakok[j].pont2[1])&&(pontok[n].y<alakok[j].pont[1]))
                    {
                        cout << "Point " << n+1 << " is contained in figure " << j+1 << endl;
                        nemvolt = false;
                    }
                else if ((alakok_tipus[j]=='c')&&(alakok[j].sugar>abs((long)(pontok[n].x-alakok[j].pont[0])))&&(alakok[j].sugar>abs((long)(pontok[n].y-alakok[j].pont[1]))))
                {
                    cout << "Point " << n+1 << " is contained in figure " << j+1 << endl;
                    nemvolt = false;
                }
            }
            if (nemvolt)
                cout << "Point " << n+1 << " is not contained in any figure" << endl;
            nemvolt = true;
    }
    /*for (int q=0; q<alakok_szam; q++)
        delete alakok[q];*/
    return 0;
}
