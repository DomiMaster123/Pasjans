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
    Karta(Kolor k, Wartosc w, bool z = true)
        : kolor(k), wartosc(w), zakryta(z) {}
    /*gettery sprawdzaja jaki jest kolor wartosc i czy karta jest zakryta pobierajac dane ze stworzonej karty*/
    Kolor pobierzKolor() const { return kolor; }
    Wartosc pobierzWartosc() const { return wartosc; }
    bool czyZakryta() const { return zakryta; }

    // funkcja do odkrywania karty
    void odkryj() { zakryta = false; }
    // funckja do zakrywania karty
    void zakryj() { zakryta = true; }
    string toString() const
    {
        string nazwyWartosci[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "D", "K"};
        string nazwyKolorow[] = {"\u2665", "\u2666", "\u2660", "\u2663"};

        return nazwyWartosci[wartosc - 1] + " " + nazwyKolorow[kolor - 1];
    }
};

class Talia
{
    vector<Karta> talia;

public:
    void tasuj()
    {
        random_device rd;
        mt19937 g(rd());
        shuffle(talia.begin(), talia.end(), g);
    }
    Karta rozdajKarte()
    {
        auto temp = talia.back();
        talia.pop_back();

        return temp;
    };
    void stworzKarty()
    {
        for (int i = 0; i <= 13; i++)
        {
            for (int y = 1; y <= 4; y++)
            {
                talia.push_back(Karta(Karta::Kolor(y), Karta::Wartosc(i)));
            }
        }
    };
    Talia()
    {

        stworzKarty();
    };
};

int main()
{
    Talia talia;
    
    for (int i = 0; i < 52; i++)
    {
        Karta temp = talia.rozdajKarte();
        cout <<i+1<< " " << temp.toString()<< endl;
    }
}
