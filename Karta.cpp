#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <stdio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

class Karta
{
public:
    // kolory kart
    enum Kolor
    {
        Kier = 1,
        Karo = 2,
        Pik = 3,
        Trefl = 4
    };
    // wartosci kart
    enum Wartosc
    {
        As = 1,
        Dwa,
        Trzy,
        Cztery,
        Piec,
        Szesc,
        Siedem,
        Osiem,
        Dziewiec,
        Dziesiec,
        Jopek,
        Dama,
        Krol
    };

private:
    // ustawienie zmiennej "kolor" o typie "Kolor" , ktora przechowuje informacje na temat koloru karty
    Kolor kolor;
    // ustawianie zmiennej "wartosc"  o typie "Wartosc" , ktora przechowuje informacje na temat wartosci karty
    Wartosc wartosc;
    // ustawianie zmiennej "zakryta" o typie bool, ktora bedzie przechowywala informacje o tym czy karta jest zakryta
    bool zakryta = true;

public:
    /*konstruktor karty, zeby stworzyc karte nalezy podac jej kolor, wartosc
     i mozna podac informacje o odkryciu lub zakryciu, bo jest ona podana domyslnie*/
    Karta(Kolor(k), Wartosc(w), bool z = true)
        : kolor(k), wartosc(w), zakryta(z) {}
    /*gettery sprawdzaja jaki jest kolor wartosc i czy karta jest zakryta pobierajac dane ze stworzonej karty*/
    Kolor getColor() const { return kolor; }
    Wartosc getValue() const { return wartosc; }
    bool isCovered() const { return zakryta; }

    // funkcja do odkrywania karty
    void uncover() { zakryta = false; }
    // funckja do zakrywania karty
    void cover() { zakryta = true; }
};

class Talia
{
    vector<Karta> talia;
    void tasuj();
    void rozdajKarte();
    public:
        Talia()
        {
            
            for (int i = 1;i<=13;i++)
            {
                for(int y = 0;y <=3;y++)
                {
                    talia.push_back(Karta(Karta::Kolor(y),Karta::Wartosc(i)));
                }
            }
            tasuj();
        }
        void tasuj()
        {
            random_device rd;
            mt19937 g(rd());
            shuffle(talia.begin(),talia.end(),g);
        }
        void rozdajKarte()
        {
            srand(time(nullptr));
            auto wylosowanaKarta = rand() % (sizeof(talia)/sizeof(Karta(Karta::Kolor::Karo,Karta::Wartosc::Jopek)))+1;



        }
};
