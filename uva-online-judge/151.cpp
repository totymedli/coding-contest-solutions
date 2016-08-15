#include <iostream>

using namespace std;

int main()
{
    int regio_ossz;
    cin >> regio_ossz;
    while (regio_ossz)//Amig nem jon nulla.
    {
        int m = 1;
        bool nincskesz = true;
        bool regiok[regio_ossz];
        regiok[0] = false;//Elso kikapcsolasa.
        for (int i=1; i<regio_ossz; i++)//Osszes eromu bekapcsol.
            regiok[i] = true;
        while (nincskesz)//Amig nem talatunk egy legkisebb jo m-et, avagy m meghatarozasa.
        {
            regiok[0] = false;//Elso kikapcsolasa.
            for (int p=1; p<regio_ossz; p++)//Osszes eromu bekapcsol.
                regiok[p] = true;
            bool wellingtonmegy = true;
            int regio_akt = 0;
            int i = 0;
            for (i=0; (i<regio_ossz)&&(wellingtonmegy); i++)//Amig az osszes regiot vagy Wellingtont le nem kapcsoljuk.
            {
                bool koveromutkeresunk = true;
                int lepnikell = m;
                while (koveromutkeresunk)//Bekapcsolt eromuvek kozul a kovetkezo m-nyire levore lepunk.
                {
                    if (regio_akt==regio_ossz-1)//Ha a regiok vegere ertunk, annak fuggvenyeben lepunk a kovetkezo regiora.
                        regio_akt = 0;
                    else
                        regio_akt++;
                    if (regiok[regio_akt])//Ha az uj regioban meg megy az eromu.
                        lepnikell--;//Egyel kevesebbet kell mar csak leni.
                    if (lepnikell==0)//Ha mar nem kell majd tobbet lepni.
                    {
                        regiok[regio_akt] = false;//Lekapcsoljuk a megtalat eromuvet.
                        koveromutkeresunk = false;//Nem lepunk tovabb.
                        if (regio_akt==12)//Ha a wllingtoni 13-as eromut nyomtuk le.
                            wellingtonmegy = false;//Nem jo megoldas.
                    }
                }
            }
            if (i==regio_ossz-1)//Ha azert vegeztunk mert minden eromut lekapcsoltunk.
            {
                nincskesz = false;//Megvan a megoldas.
                cout << m << endl;
            }
            else
                m++;//Egyebkent megnezzuk kovetkezo m-re.
        }
        cin >> regio_ossz;//Ujsor.
    }
    return 0;
}
