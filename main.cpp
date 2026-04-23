#include "kniha.h"
#include <iostream>

using namespace std;

int main() {
    // testovani ruznych zpusobu vytvoreni objektu
    Kniha k1; 
    Kniha k2("978-80-251-1583-1", "jesse liberty", "naucte se c++ za 21 dni");
    Kniha k3 = k2; 

    cout << "k1 vychozi:\n" << k1 << endl;
    cout << "k2 parametry:\n" << k2 << endl;
    cout << "k3 kopie:\n" << k3 << endl;

    string i, a, n;
    char volba;
    
    // nekonecna smycka pro uzivatele
    do {
        cout << "\n--- zadani udaju o knize ---" << endl;
        cout << "isbn (i s pomlckami): ";
        getline(cin >> ws, i);
        cout << "autor: ";
        getline(cin, a);
        cout << "nazev: ";
        getline(cin, n);

        // kontrola a ulozeni
        if (k1.setKniha(i, a, n)) {
            cout << "\nulozeno!\n" << k1;
            cout << "ciste isbn: " << k1.getIsbnBezPomlcek() << endl;
            cout << "delka bez pomlcek: " << k1.getDelkaBezPomlcek() << endl;
        } else {
            cout << "\nchyba: spatne isbn nebo text!" << endl;
        }

        cout << "chces zadat dalsi? (a/n): ";
        cin >> volba;
    } while (volba == 'a' || volba == 'A');

    return 0;
}
