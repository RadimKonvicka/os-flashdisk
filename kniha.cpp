#include "kniha.h"

using namespace std;

// zakladni nastaveni prazdne knihy
Kniha::Kniha() {
    isbn = "0-00-000000-0";
    autor = "neznamy";
    nazev = "neznamy";
}

// vytvoreni knihy s daty, pokud jsou ok
Kniha::Kniha(string i, string a, string n) {
    if (!setKniha(i, a, n)) {
        isbn = "0-00-000000-0";
        autor = "neznamy";
        nazev = "neznamy";
    }
}

// kopirovani jedne knihy do druhe
Kniha::Kniha(const Kniha& jina) {
    isbn = jina.isbn;
    autor = jina.autor;
    nazev = jina.nazev;
}

// funkce co vymaze pomlcky a necha jen cisla a x
string Kniha::odstranPomlcky(string s) const {
    string ciste = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {
            ciste += s[i];
        }
    }
    return ciste;
}

// vypocet jestli je isbn v poradku
bool Kniha::jeValidniISBN(string s) const {
    string c = odstranPomlcky(s);
    
    // kontrola pro isbn-10
    if (c.length() == 10) {
        int suma = 0;
        for (int i = 0; i < 9; i++) {
            if (!isdigit(c[i])) return false;
            suma += (c[i] - '0') * (10 - i);
        }
        int kontrola = (c[9] == 'X' || c[9] == 'x') ? 10 : (c[9] - '0');
        return (suma + kontrola) % 11 == 0;
    }
    
    // kontrola pro isbn-13
    if (c.length() == 13) {
        int suma = 0;
        for (int i = 0; i < 13; i++) {
            if (!isdigit(c[i])) return false;
            int vaha = (i % 2 == 0) ? 1 : 3;
            suma += (c[i] - '0') * vaha;
        }
        return suma % 10 == 0;
    }
    return false;
}

// nastaveni hodnot jen kdyz projdou kontrolou
bool Kniha::setKniha(string i, string a, string n) {
    if (jeValidniISBN(i) && a.length() >= 3 && n.length() >= 3) {
        isbn = i;
        autor = a;
        nazev = n;
        return true;
    }
    return false;
}

// vrati prvni tri cisla u isbn-13
string Kniha::getPrefix() const {
    string c = odstranPomlcky(isbn);
    return (c.length() == 13) ? c.substr(0, 3) : "neni";
}

// urci region podle cisla v isbn
string Kniha::getRegion() const {
    string c = odstranPomlcky(isbn);
    string r = (c.length() == 13) ? c.substr(3, 2) : c.substr(0, 2);
    if (r == "80") return r + " (cesky, slovensky)";
    if (r[0] == '0' || r[0] == '1') return r.substr(0,1) + " (anglicky)";
    return r;
}

// vrati isbn bez pomlcek
string Kniha::getIsbnBezPomlcek() const { 
    return odstranPomlcky(isbn); 
}

// vrati kolik ma isbn znaku bez pomlcek
int Kniha::getDelkaBezPomlcek() const { 
    return odstranPomlcky(isbn).length(); 
}

// operator rovna se
Kniha& Kniha::operator=(const Kniha& jina) {
    if (this != &jina) {
        isbn = jina.isbn;
        autor = jina.autor;
        nazev = jina.nazev;
    }
    return *this;
}

// operator pro porovnani
bool Kniha::operator==(const Kniha& jina) const {
    return (isbn == jina.isbn && autor == jina.autor && nazev == jina.nazev);
}

// jak se ma kniha vypsat do cout
ostream& operator<<(ostream& os, const Kniha& k) {
    os << "isbn: " << k.isbn << " | prefix: " << k.getPrefix() << endl;
    os << "region: " << k.getRegion() << " | autor: " << k.autor << endl;
    os << "nazev: " << k.nazev << endl;
    return os;
}
