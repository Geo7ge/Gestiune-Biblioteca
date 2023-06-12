#include "Carte.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <windows.h>


using namespace std;
Carte::Carte()
{
    //ctor
}

Carte::~Carte()
{
    //dtor
}

void Carte::IntroducereDateTastatura(int NrCarti)
{
    cout << "Introduceti titlul:  ";
    //cin.clear();
    while (std::cin.get() != '\n')
        continue;
    getline(cin, Titlu);
    //cin >> Titlu;
    cout << "Introduceti autorul:  ";
    cin.clear();
    getline(cin, Autor);
    //cin >> Autor;
    cout << "Introduceti anul publicatiei:  ";
    cin.clear();
    cin >> anPublicatie;
    while (std::cin.get() != '\n')
        continue;
    cout << "Introduceti editura:  ";
    cin.clear();
    getline(cin, Editura);

    //cin >> Editura;
    cout << "Introduceti numarul de pagini:  ";
    cin.clear();

    cin >> nrPagini;
    cout << "Introduceti genul literar din care apartine:  ";
    while (std::cin.get() != '\n')
        continue;
    cin.clear();
    getline(cin, genLiterar);

    //cin >> genLiterar;
    cout << "Introduceti o scurta descriere pentru carte:  ";
    cin.clear();
    getline(cin, Descriere);

    //cin >> Descriere;
    ID = NrCarti;
}

void Carte::CitesteDateFisier(string LinieFisier)
{
    char* P;
    char* str = new char[LinieFisier.length() + 1];
    strcpy(str, LinieFisier.c_str());
    P = strtok(str, ";");
    ID = atoi(P);
    P = strtok(NULL, ";");
    Titlu = P;
    P = strtok(NULL, ";");
    Autor = P;
    P = strtok(NULL, ";");
    anPublicatie = atoi(P);
    P = strtok(NULL, ";");
    Editura = P;
    P = strtok(NULL, ";");
    nrPagini = atoi(P);
    P = strtok(NULL, ";");
    genLiterar = P;
    P = strtok(NULL, ";");
    Descriere = P;
    delete[] str;
}


void Carte::AfisareCarte()
{
    cout << "Informatiile despre carte sunt:" << endl;
    cout << "ID: " << ID;
    cout << " ;Titlu: " << Titlu;
    cout << " ;Autor: " << Autor;
    cout << " ;An publicatie: " << anPublicatie;
    cout << " ;Editura: " << Editura;
    cout << " ;Numar pagini: " << nrPagini;
    cout << " ;Genul literar: " <<genLiterar;
    cout << "\nDescrierea cartii este: "  << Descriere << endl;

}

void Carte::SalvareCartiFisier(fstream& file)
{
    file << ID << ";";
    file << Titlu << ";";
    file << Autor << ";";
    file << anPublicatie << ";";
    file << Editura << ";";
    file << nrPagini << ";";
    file << genLiterar << ";";
    file << Descriere << ";" << "\n";
}

void Carte::SalvareCartiFisier(fstream& file, int id)
{
    file << id << ";";
    file << Titlu << ";";
    file << Autor << ";";
    file << anPublicatie << ";";
    file << Editura << ";";
    file << nrPagini << ";";
    file << genLiterar << ";";
    file << Descriere << ";" << "\n";
}

int Carte::GetAnPublicatie()
{
    return anPublicatie;
}

int Carte::GetNrPagini()
{
    return nrPagini;
}
