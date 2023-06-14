#include "Carte.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cstdio>


using namespace std;


int id = 0;
const int MaxNrCarti = 100;
int NrCarti = 0;

void SortareDupaAn(Carte Carti[])
{
    int sortare[NrCarti];
    for (int i = 0; i < NrCarti; i++)
    {
        sortare[i] = i;
    }
    bool s;
    for (int i = 0; i < NrCarti - 1; i++)
    {
        s = false;
        for (int j = 0; j < NrCarti - i - 1; j++)
        {
            if (Carti[sortare[j]].GetAnPublicatie() > Carti[sortare[j + 1]].GetAnPublicatie())
            {
                swap(sortare[j], sortare[j+1]);
                s = true;
            }
        }
        if (!s)
            break;
    }
    for (int i = 0; i < NrCarti; i++)
    {
        Carti[sortare[i]].AfisareCarte();
    }
}

void SortareDupaPagini(Carte Carti[]){
    int sortare[NrCarti];
    for (int i = 0; i < NrCarti; i++)
    {
        sortare[i] = i;
    }
    bool s;
    for (int i = 0; i < NrCarti - 1; i++)
    {
        s = false;
        for (int j = 0; j < NrCarti - i - 1; j++)
        {
            if (Carti[sortare[j]].GetNrPagini() > Carti[sortare[j + 1]].GetNrPagini())
            {
                swap(sortare[j], sortare[j+1]);
                s = true;
            }
        }
        if (!s)
            break;
    }
    for (int i = 0; i < NrCarti; i++)
    {
        Carti[sortare[i]].AfisareCarte();
    }
}

void SortareDupaAutor(Carte Carti[]){
    int sortare[NrCarti];
    for (int i = 0; i < NrCarti; i++)
    {
        sortare[i] = i;
    }
    bool s;
    string autor1;
    string autor2;
    for (int i = 0; i < NrCarti - 1; i++)
    {
        s = false;
        for (int j = 0; j < NrCarti - i - 1; j++)
        {
            autor1 = Carti[sortare[j]].GetAutor();
            autor2 = Carti[sortare[j+1]].GetAutor();
            if (autor1[0] > autor2[0])
            {
                swap(sortare[j], sortare[j+1]);
                s = true;
            }
        }
        if (!s)
            break;
    }
    for (int i = 0; i < NrCarti; i++)
    {
        Carti[sortare[i]].AfisareCarte();
    }
}

void SortareDupaTitlu(Carte Carti[]){
    int sortare[NrCarti];
    for (int i = 0; i < NrCarti; i++)
    {
        sortare[i] = i;
    }
    bool s;
    string titlu1;
    string titlu2;
    for (int i = 0; i < NrCarti - 1; i++)
    {
        s = false;
        for (int j = 0; j < NrCarti - i - 1; j++)
        {
            titlu1 = Carti[sortare[j]].GetTitlu();
            titlu2 = Carti[sortare[j+1]].GetTitlu();
            if (titlu1[0] > titlu2[0])
            {
                swap(sortare[j], sortare[j+1]);
                s = true;
            }
        }
        if (!s)
            break;
    }
    for (int i = 0; i < NrCarti; i++)
    {
        Carti[sortare[i]].AfisareCarte();
    }
}

fstream StergeCarte(Carte Carti[], fstream &file)
{
    fstream tempFile("Carti.tmp",  ios::out);
    int x;
    int iD = 0;
    do
    {
    cout << "Introdceti numarul pentru a fi sters: ";
    cin >> x;
    }while(x < 0 && x < NrCarti);

    for(int i = 0; i < NrCarti; i++)
    {
        if (i != x)
        {
            Carti[i].SalvareCartiFisier(tempFile, iD++);
        }
    }
    file.close();
    tempFile.close();
    //return tempFile;

    if (remove("Carti.txt") != 0) {
        cerr << "Failed to delete the original file." << endl;
    }
    if (rename("Carti.tmp", "Carti.txt") != 0)
        cerr << "Failed to rename the temporary file." << endl;
    fstream File("Carti.txt", ios::in | ios::out);
    return File;
}


int main()
{
    Carte Carti[MaxNrCarti];
    fstream file("Carti.txt", ios::in | ios::out);
    string line;

    while (getline(file, line))
    {
        Carti[NrCarti++].CitesteDateFisier(line);
        id++;
    }

    char optiune ;
    do
    {
        cout << "Alegeti optiunea dorita:" << endl;
        cout << "C - Citire date din fisier." << endl;
        cout << "I - Introduceti o carte de la tastatura." << endl;
        cout << "A - Afisare carti din fisier." << endl;
        cout << "B - Afisare carti dupa anul de publicatie in ordine crescatoare." << endl;
        cout << "D - Afisare carti dupa numarul de pagini in ordine crescatoare." << endl;
        cout << "E - Afisare carti dupa autor in ordine alfabetica." << endl;
        cout << "F - Afisare carti dupa titlu in ordine alfabetica." << endl;
        cout << "S - Stergere carte din fisier." << endl;
        cout << "M - Salvare carte in fisier." << endl;
        cout << "X - Oprire program." << endl;
        cin >> optiune;

        switch(toupper(optiune))
        {
        case 'I':
            Carti[NrCarti].IntroducereDateTastatura(NrCarti);
            NrCarti++;
            cout << "***CARTEA A FOST INTRODUSA CU SUCCES***" << endl;

            break;
        case 'C':
            id = 0;
            NrCarti = 0;
            file.clear();
            file.seekp(0, ios::beg); // setează poziția de scriere la începutul fișierului
            file.seekg(0, ios::beg); // setează poziția de citire la începutul fișierului
            while (getline(file, line))
            {
                Carti[NrCarti++].CitesteDateFisier(line);
                id++;
            }

            break;
        case 'A':
                for(int i = 0; i < NrCarti; i++)
                {
                    Carti[i].AfisareCarte();
                }

            break;
        case 'B':
            SortareDupaAn(Carti);

            break;
        case 'D':
            SortareDupaPagini(Carti);

            break;
        case 'E':
            SortareDupaAutor(Carti);

            break;
        case 'F':
            SortareDupaTitlu(Carti);

            break;
        case 'S':
                file = StergeCarte(Carti, file);
                NrCarti--;
                id--;
                cout << "***CARTEA A FOST STEARSA CU SUCCES***" << endl;

            break;
        case 'M':
                file.clear();
                file.seekp(0, ios::beg); // setează poziția de scriere la începutul fișierului
                file.seekg(0, ios::beg); // setează poziția de citire la începutul fișierului
                for(int i = 0; i < NrCarti; i++)
                {
                    Carti[i].SalvareCartiFisier(file);
                }

            break;
        case 'X':

            break;
        default:
            cout << "Optiune introdusa gresit" << endl;

            break;
        }
    }while(toupper(optiune) != 'X');
    file.close();

}

/*
1;Misterul crimei fara cadavru;Agatha Christie;2022;Litera;288;Roman politist;Imediat ce Gwenda se muta in noua ei locuinta incep sa se petreaca lucruri ciudate;
2;Misterul de la Blackwood;Lois Duncan;2019;Leda Edge;192;Roman politist;Cand Kit Gordy zarestte maiestosul conac de la Blackwood dincolo de portile negre de fier nu se poate abtine sa nu se gandeasca"Locul asta e .... malefic"!;
3;Cum sa pictezi un mort;Sarah Hall;2011;Litera;304;Roman politist;In Italia anilor '60, Signor Giorgio, un pictor de naturi moarte, traieste obsedat de redarea pe panza a relatiilor de lunimi si umbre dintre obiecte.;
4;Ultima geana de lumina;Kristin Harmel;2021;Litera;368;Roman de Dragoste;Ines tocmai a devenit sotia lui Michel, proprietarul legendarei case producatoare de sampanie numite Maison Chauveau, cand germanii invadeaza Franta.;
5;Padurea stelelor ce pier;Kristin Harmel;2022;Litera;400;Roman de dragoste;O poveste impresionanta despre o tanara ce isi foloseste cunostiintele legate de viata in salbaticie pentru a ajuta refugiatii evrei sa scape de nazisti.;
6;Cartea inelelor;Andrei Ruse;2023;Hyperliteratura;408;Fantezie;Aleodor va trebui sa trezeasca spiritele celor morti din inchipuirea ca-s vii.;
7;Cartea Blestemelor;Andrei Ruse;2022;Hyperliteratura;384;Fantezie;Intr-o noapte friguroasa, sapte oraseni se intorc la palat, aducand cu ei un strain misterios, de pe un taram necunoscut, care stie de ce fiul imparatului oamenilor nu se trezeste la viata.;
8;Totul despre creier;Gabriel Tudor;2022;Litera;224;Enciclopedie;Cel mai simplu si cel mai ilustrat ghid despre CREIER.;
9;Inainte de sfarsit e intotdeauna prea devreme;Matei Calinescu;2023;Humanitas;172;Poezie;-;
10;Insula misterioasa;Jules Verne;2016;Andreas;176;Aventura;In 1865, in timpul razboiului de secesiune, cinci oameni au plecat imbracati intr-un balon, din Richmond, caputala Virginiei, care era atunci asediata de sudisti.;
*/
