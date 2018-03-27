#include "testy.h"
#include "zbior4.h"

void menuglowne() ;
void menudzialania(zbior &A, zbior &B) ;
void menuinne(zbior &A , zbior &B) ;
void poprawnosc() ;
void wyczysc() { while ( getc(stdin) != '\n' ) ;}


int main()
{
   menuglowne() ;
   return 0 ;
}
void menuglowne()
{
    int wybor = 0 ;
    int licznosc ;
    zbior wynik ;
    cout << "Program tworzy zbiory liczb rzeczywistych " << endl ;
    cout << "Zdefiniuj zbior A\nPodaj liczbe elementow" << endl ;
    poprawnosc() ;
    cin >> licznosc ;
    wyczysc() ;
    zbior A(licznosc) ;
    wyczysc() ;
    cout << "Zdefiniuj zbior B\nPodaj liczbe elementow" << endl ;
    poprawnosc() ;
    cin >> licznosc ;
    wyczysc() ;
    zbior B(licznosc) ;
    cout<< "Zbior A:" << A << endl ;
    cout << "Zbior B:" << B << endl ;
    while (wybor != 5 )
    {
        cout << "MENU GLOWNE\n1- Dzialania na zbiorach\n2 - Inne dzialania\n3 - Wyswietl zbiory\n4 - Testowanie\n5 - koniec" << endl ;
        cin >> wybor ;
        switch (wybor)
        {
            case 1: menudzialania(A,B) ;
            break ;
            case 2:menuinne(A,B) ;
            break ;
            case 3: cout << "Zbior A:" << A << endl << "Zbior B:" << B << endl ;
            break ;
            case 4:test() ;
            break ;
            case 5: break ;
            default : cout << "Prosze wybrac jedna z opcji" << endl ;
        }
    }
}
void menudzialania(zbior &A , zbior &B)
{
    int wybor  = 0 ;
    zbior wynik ;
    while (wybor != 9)
    {
        cout << "MENU DZIALANIA\n1 - suma A+B\n2 - suma A = A+B\n3 - roznica A - B\n4 - roznica A = A - B\n5 - przeciecie A * B" << endl ;
        cout << "6 - przeciecie A = A * B\n7 - sprawdzenie, czy zbiory sa rowne\n8 - sprawdzenie, czy zbiory sa rozne" << endl ;
        cout << "9 - powrot do menu glownego" << endl ;
        poprawnosc() ;
        cin >> wybor ;
        switch (wybor)
        {
            case 1: wynik = A + B ;
                    cout << "Wynik: " << wynik << endl;
            break;
            case 2: A+=B ;
                    cout << A ;
            break ;
            case 3: wynik  = A - B ;
                    cout << "Wynik: " << wynik << endl;
            break ;
            case 4: A-=B ;
                    cout << A ;
            break ;
            case 5: wynik = A * B ;
                    cout << "Wynik: " << wynik << endl;
            break ;
            case 6: A*=B ;
                    cout << A ;
            break ;
            case 7: if ((A==B) == true )
                    {
                        cout << "Zbiory sa rowne" << endl ;
                    } else
                    {
                        cout << "Zbiory sa rozne" << endl ;
                    }
            break ;
            case 8: if ((A!=B) == false )
                    {
                        cout << "Zbiory sa rowne" << endl ;
                    } else
                    {
                        cout << "Zbiory sa rozne" << endl ;
                    }
            break ;
            case 9: break ;
            default: cout << "Prosze wybrac jedna z opcji" << endl ;


        }
    }
}
void menuinne(zbior &A , zbior &B)
{
    int wybor = 0 ;
    while (wybor != 7)
    {
        cout<< "MENU INNE\nDodaj element\n1 - zbior A\t2 - zbior B\nUsun element\n3 - zbior A\t4 - zbior B\n5 - licznosc zbiorow" << endl ;
        cout << "6 - sprawdzenie, czy element nalezy do zbiorow\n7 - powrot do menu glownego" << endl ;
        cin >> wybor ;
        switch (wybor)
        {
            case 1: A.dodajnowa() ;
            break ;
            case 2: B.dodajnowa() ;
            break ;
            case 3: A.usun() ;
            break ;
            case 4: B.usun() ;
            break ;
            case 5: cout << "Zbior A: ";
                    A.licznosc() ;
                    cout << endl << "Zbior B: ";
                    B.licznosc() ;
                    cout << endl ;
            break ;
            case 6: cout << "Zbior A: ";
                    A.czynalezy() ;
                    cout << endl << "Zbior B: ";
                    B.czynalezy() ;
                    cout << endl ;
            break ;
            case 7: break ;
            default: cout << "Prosze wybrac jedna z opcji" << endl ;
        }
    }
}
void poprawnosc()
{
    char test ;
    while ( !isdigit(test = getc(stdin)) )
    {
        while ( getc(stdin) != '\n' ) ;
        cout << "Prosze wprowadzic liczbe calkowita" << endl ;
    }
    ungetc(test,stdin) ;
}
