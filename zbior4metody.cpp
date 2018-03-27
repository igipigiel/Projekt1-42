#include "zbior4.h"

zbior::zbior()
{
    int indeks ;
    rozmiar = DOMYSLNY ;
    liczby = new float [rozmiar] ; // tworzy tablice liczb o domyslnym rozmiarze
    for (indeks = 0 ; indeks < rozmiar ; indeks++)
    {
        liczby[indeks] = 0.0 ; // i ustawia elementy na 0
    }
    ilosc = 0 ; // zbior jest pusty

}
zbior::zbior(int ile)
{
    int indeks ;
    liczby = new float [ile] ;
    rozmiar = ilosc = ile ;
    for (indeks = 0 ; indeks < ilosc ; indeks++)
    {
        dodajliczbe(indeks) ;
    }
}
zbior::zbior(int ile , float *temp)
{
    int indeks ;
    liczby = new float [ile] ;
    rozmiar = ilosc = ile ;
    for ( indeks = 0 ; indeks < ile ; indeks++)
    {
        liczby[indeks] = temp[indeks] ;
    }
}
void zbior::dodajliczbe(int i)
{
    char test ;
    int miejsce; // potrzebne przy dodawaniu 0 jako elementu
    float test2 ;
    cout << "Prosze podac liczbe" << endl ;
    cin >> test ;
    poprawnosc(test) ;
    cin >> test2 ;
    while ( (miejsce = czybyla(test2 , ilosc)) != -1 && miejsce < i ) // nie dodaje 0 tylko, jesli bylo juz wpisane
    {
        cout << "Liczba wystepuje juz w zbiorze" << endl ;
        cin >> test2 ;
    }
    liczby[i] = test2 ;
}
void zbior::poprawnosc(char t)
{
    while (!isdigit(t) && t != '-')
    {
            wyczysc() ;
            cout << "Prosze wprowadzic liczbe rzeczywista" << endl ;
            cin >> t ;
    }
    ungetc(t , stdin) ; // zwraca znak do lancucha wejsciowego
}
int zbior::czybyla(float dana, int k)
{
    int i ;
    for ( i = 0 ; i < k ; i++ )
    {
      if ( dana == liczby[i] ) return i ;
    }
    return -1 ;
}
int zbior::czywinnym(float dana, int k, const zbior &B)
{
    int i ;
    for ( i = 0 ; i < k ; i++ )
    {
      if ( dana == B.liczby[i] ) return i ;
    }
    return -1 ;
}
void zbior::czynalezy()
{
    char test ;
    float test2 ;
    wyczysc() ;
    cout << "Prosze podac liczbe" << endl ;
    test = getc(stdin) ;
    poprawnosc(test) ;
    cin >> test2 ;
    if ( czybyla(test , ilosc) == -1 )
    {
        cout << "Liczba nie wystepuje w zbiorze" << endl ;
        return ;
    }
    else cout << "Liczba wystepuje w zbiorze" << endl ;
}
void zbior::wyczysc()
{
    while ( getc(stdin) != '\n' ) ;
}
void zbior::dodajnowa()
{
    if ( ilosc == rozmiar ) // zbior pelny
    {
        cout << "Nie mozna dodac juz wiecej liczb do zbioru\n" ;
        return ;
    }
    dodajliczbe(ilosc++) ;
}
void zbior::usun()
{
    float dana ;
    int i ;
    if (ilosc == 0)
    {
        cout << "Zbior jest juz pusty!" << endl ;
        return ;
    }

    cout << "Podaj liczbe do usuniecia" << endl ;
    cin >> dana ;
    while ((i = czybyla(dana, ilosc)) == -1 )
    {
        wyczysc() ;
        cout << "Prosze wprowadzic liczbe, wystepujaca w zbiorze" << endl ;
        cin >> dana ;
    }
    liczby[i] = liczby[--ilosc] ;
    cout << "Zostalo liczb:" << ilosc << endl ;
    for ( i = 0 ; i < ilosc ; i++ ) cout << liczby[i] << "\t" ;
    cout << endl ;
}
void zbior::operator=( const zbior &B )
{
    float * temp ;
    int indeks ;
    if ( rozmiar < B.ilosc ) // przypisanie zbioru wiekszego do mniejszego
    {
        temp = liczby ;
        liczby = new float [B.ilosc] ;
        delete [] temp ;

    }
    for ( indeks = 0 ; indeks < B.ilosc ; indeks++ )
    {
       liczby[indeks] = B.liczby[indeks] ;
    }
    rozmiar = ilosc = B.ilosc ;
}
zbior zbior::operator*(const zbior &B)
{
    zbior przeciecie ;
    int indeks;
    int i = 0 ;
    for (indeks = 0 ; indeks < ilosc ; indeks++)
    {
        if ( czywinnym(liczby[indeks], B.ilosc , B) != -1 ) // sprawdzenie czy el. wystepuje w B
        {
            przeciecie.liczby[i] = liczby[indeks] ;
            i++ ;
            przeciecie.ilosc++ ;
        }
    }
    return przeciecie ;
}

zbior zbior::operator-(const zbior &B)
{
    zbior roznica ;
    int indeks ;
    int i = 0 ;
    for ( indeks = 0 ; indeks < ilosc ; indeks ++ )
    {
        if (czywinnym(liczby[indeks], B.ilosc , B) == -1)
        {
            roznica.liczby[i] = liczby[indeks] ;
            i++ ;
            roznica.ilosc++ ;
        }
    }
    return roznica ;
}
zbior zbior::operator+(const zbior &B)
{
    zbior suma , roznica ;
    roznica = *this - B ;
    int indeks ;
    for (indeks = 0 ; indeks < B.ilosc ; indeks++) // przepisanie zbioru B
    {
        suma.liczby[indeks] = B.liczby[indeks] ;
    }
    for (indeks = 0 ;indeks < roznica.ilosc ; indeks++ ) // i roznicy A-B
    {
        suma.liczby[indeks + B.ilosc] = roznica.liczby[indeks] ;
    }
    suma.ilosc = B.ilosc + roznica.ilosc ;
    return suma ;
}
bool zbior::operator==(const zbior &B)
{
    int indeks ;
    if (ilosc != B.ilosc) // zbiory o roznych licznosciach nie moga byc rowne
    {
        return false;
    }
    for (indeks = 0 ; indeks < ilosc ; indeks++)
    {
        if ( czywinnym( liczby[indeks] , B.ilosc , B ) == -1 ) // jesli chociaz jeden element jest rozny
        {
            return false ;
        }
    }
    return true ;

}


zbior::~zbior()
{
    delete [] liczby ;
}
ostream & operator<<( ostream &sb , const zbior &B)
{
    int i ;
    if ( B.ilosc == 0  )
    {
        cout << "Wybrany zbior jest pusty" << endl ;
        return sb ;
    }
    for ( i = 0 ; i < B.ilosc ; i++ )
    {
        sb << B.liczby[i] << " " ;
    }
    return sb ;
}
