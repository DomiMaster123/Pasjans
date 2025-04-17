#include <iostream>
#include <string>

using namespace std;

class Card
{
    public:

    //kolory kart
    enum class Color {Kier,Karo,Pik,Trefl};
    //wartosci kart
    enum class Value {As = 1,Dwa,Trzy,Cztery,Piec,Szesc,Siedem,Osiem,Dziewiec,Dziesiec,Jopek,Dama,Krol};

    private:
    // ustawienie zmiennej "color" o typie "Color" , ktora przechowuje informacje na temat koloru karty
    Color color;
    //ustawianie zmiennej "value"(wartosc)  o typie "Value" , ktora przechowuje informacje na temat wartosci karty
    Value value;
    //ustawianie zmiennej "covered" o typie bool, ktora bedzie przechowywala informacje o tym czy karta jest zakryta
    bool covered = true;

    public:
    /*konstruktor karty, zeby stworzyc karte nalezy podac jej kolor, wartosc
     i mozna podac informacje o odkryciu lub zakryciu, bo jest ona podana domyslnie*/
    Card(Color(c),Value(v),bool z = true)
        :color(c),value(v),covered(z){}
    /*gettery sprawdzaja jaki jest kolor wartosc i czy karta jest zakryta pobierajac dane ze stworzonej karty*/
    Color getColor() const {return color;}
    Value getValue() const {return value;}
    bool isCovered() const {return covered;}

    //funkcja do odkrywania karty
    void uncover() { covered = false;}
    //funckja do zakrywania karty
    void cover() { covered = true;}




};