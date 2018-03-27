#ifndef ZBIOR4_H_INCLUDED
#define ZBIOR4_H_INCLUDED
#define DOMYSLNY 30
#include <iostream>
#include <cstdio>
#include <ctype.h>

using namespace std ;

class zbior{
    float *liczby ;
    int ilosc ; // ilosc elementow
    int rozmiar ; // rozmiar, razem z pustymi miejscami w zbiorze
public:
    zbior() ; // konstruktor domyslny
    zbior(int) ; // konstruktor do recznego tworzenia
    zbior(int , float *) ; // konstruktor do testow, szybkiego wczytania
    void dodajliczbe(int i) ; // dodaje liczbe do zbioru
    void poprawnosc(char t) ; // sprawdza, czy wprowadzono liczbe
    int czybyla(float dana, int k) ; // sprawdza, czy liczba wystepuje w zbiorze i na ktorym miejscu
    int czywinnym(float dana, int k, const zbior &B) ; // sprawdza, czy liczba wystapila w innym zbiorze
    void czynalezy() ; // wyswietla komunikat, czy liczba wystepuje w zbiorze
    void wyczysc() ; // czysci strumien wejsciowy
    void dodajnowa() ; // dodanie nowej liczby do istniejacego zbioru
    void usun() ; // usuniecie liczby ze zbioru
    inline void licznosc() {cout << ilosc ; } ; // wyswietlenie ilosci liczb w zbiorze
    friend ostream & operator<<( ostream & ,const zbior &) ;
    void operator=( const zbior &B ) ;
    zbior operator*(const zbior &B) ;
    inline void operator*=(const zbior &B) {*this = (*this * B) ;} ;
    zbior operator-(const zbior &B) ;
    inline void operator-=(const zbior &B) {*this = *this - B ;} ;
    zbior operator+(const zbior &B) ;
    inline void operator+=(const zbior &B) { *this = *this + B ; } ;
    bool operator==(const zbior &B) ;
    inline bool operator!=(const zbior &B) { if ( *this == B ) return false ; else return true; }
    ~zbior() ; // destruktor
    };

#endif // ZBIOR4_H_INCLUDED
