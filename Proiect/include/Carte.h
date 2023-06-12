#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Carte
{
    public:
        Carte();
        virtual ~Carte();
        void CitesteDateFisier(string LinieFisier);
        void IntroducereDateTastatura(int NrCarti);
        void SalvareCartiFisier(fstream& file);
        void SalvareCartiFisier(fstream& file, int id);
        int GetAnPublicatie();
        int GetNrPagini();
        void AfisareCarte();

    protected:

    private:
        int ID;
        string Titlu;
        string Autor;
        int anPublicatie;
        string Editura;
        int nrPagini;
        string genLiterar;
        string Descriere;
};
#endif // CARTE_H
