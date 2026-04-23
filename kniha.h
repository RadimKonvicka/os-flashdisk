#ifndef KNIHA_H
#define KNIHA_H

#include <string>
#include <iostream>

class Kniha {
private:
    // schovane promenne pro data
    std::string isbn;
    std::string autor;
    std::string nazev;

    // pomocne funkce na kontrolu
    bool jeValidniISBN(std::string s) const; 
    std::string odstranPomlcky(std::string s) const; 

public:
    // konstruktory
    Kniha(); 
    Kniha(std::string i, std::string a, std::string n);
    Kniha(const Kniha& jina);

    // funkce na praci s daty
    bool setKniha(std::string i, std::string a, std::string n);
    std::string getIsbn() const { return isbn; }
    std::string getAutor() const { return autor; }
    std::string getNazev() const { return nazev; }

    // funkce na rozbor isbn
    std::string getPrefix() const;
    std::string getRegion() const;
    std::string getVydavatel() const;
    std::string getVydani() const;
    std::string getIsbnBezPomlcek() const;
    int getDelkaBezPomlcek() const;

    // operatory
    Kniha& operator=(const Kniha& jina);
    bool operator==(const Kniha& jina) const;

    // vypis do konzole
    friend std::ostream& operator<<(std::ostream& os, const Kniha& k);
};

#endif
