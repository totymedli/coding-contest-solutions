#include <iostream>

using namespace std;

int main()
{
    struct zeneszam
    {
        int szamhossz, sorszam;
        bool szalagonvan;
    };

    zeneszam nullszam;
    nullszam.sorszam = 50;
    nullszam.szamhossz = 0;
    //nullszam.szalagonvan = false;
    zeneszam* leghosszabbszam = &nullszam;
    int szalaghossz, zeneszam_max, szabadhely, zenek_szalagon_db, osszeg;
    while (cin)
    {
        cin >> szalaghossz >> zeneszam_max;
        zeneszam zenek[zeneszam_max];
        zeneszam* zenek_szalagon[zeneszam_max];
        zenek_szalagon_db = 0;
        for (int i=0; i<zeneszam_max; i++)
        {
            cin >> zenek[i].szamhossz;
            zenek[i].sorszam = i;
            zenek[i].szalagonvan = false;
        }
        szabadhely = szalaghossz;
        int u = 0;
        while (szabadhely!=0||u<zeneszam_max)
        {
            for (int i=0; i<zeneszam_max; i++)
            {
                if ((zenek[i].szamhossz>leghosszabbszam->szamhossz)&&(!zenek[i].szalagonvan))
                leghosszabbszam = &zenek[i];
            }
            if (leghosszabbszam->szamhossz<=szabadhely)
            {
                zenek_szalagon[zenek_szalagon_db] = leghosszabbszam;
                szabadhely -= leghosszabbszam->szamhossz;
                zenek_szalagon_db++;
            }
                leghosszabbszam->szalagonvan = true;//Akar raraktuk valosagosan a szalagra, akar nem, ezt mar nem akarjuk tobbet a szalagra rakni, mert vagy rakerult, vagy nem fer ra.
            u++;
            leghosszabbszam = &nullszam;
        }
        osszeg = 0;
        for (int h=0; h<zenek_szalagon_db; h++)
        {
            leghosszabbszam = &nullszam;//Ezt fogjuk hasznalni a legkissebb sorszamu elemek tarolasara.
            for (int r=0; r<zenek_szalagon_db; r++)
            {
                if ((zenek_szalagon[r]->sorszam<=leghosszabbszam->sorszam)&&(zenek_szalagon[r]->szalagonvan))
                    leghosszabbszam = zenek_szalagon[r];
            }
            leghosszabbszam->szalagonvan = false;//Levesszuk a szalagrol, hogy tobbet ne talaljuk meg mint legkisebb sorszamu elem.
            cout << leghosszabbszam->szamhossz << " ";
            osszeg += leghosszabbszam->szamhossz;
        }
        cout << "sum:" << osszeg;
    }
    return 0;
}
