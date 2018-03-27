#include "testy.h"
float c[rozC] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8} ;
zbior C(rozC , c) ;
float d[rozD] = { 1 , 5 , 6.7 , 88 , 0 } ;
zbior D( rozD , d ) ;
void test()
{
    int poprawne = 5;
    if (testprzypisanie() == false )
    {
        cout << "Operator = nie dziala poprawnie" << endl ;
        poprawne-- ;
    }
    if ( testrownosc() == false )
    {
        cout << "Operator == i != nie dzialaja poprawnie" << endl ;
        poprawne-- ;
    }
    if (testsuma() == false)
    {
        cout << "Operator + i += nie dzialaja poprawnie" << endl ;
        poprawne-- ;
    }
    if (testroznica() == false)
    {
        cout << "Operator - i -= nie dzialaja poprawnie" << endl ;
        poprawne-- ;
    }
    if (testprzeciecie() == false)
    {
        cout << "Operator * i *= nie dzialaja poprawnie" << endl ;
        poprawne-- ;
    }
    if ( poprawne == 5 )
    {
        cout << "Wszystkie operatory dzialaja poprawnie" << endl ;
    }
}
bool testprzypisanie()
{
    zbior wynik;
    wynik = C ;
    if ( wynik == C )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}
bool testrownosc()
{
    zbior E(rozC,c) ;
  if ( (C == E) == 0 || (C!=E) == 1 )
  {
      return false ;
  }
  else
  {
      return true ;
  }

}
bool testsuma()
{
    float s[] = {1,2,3,4,5,6,6.7,7,8,88,0} ;
    zbior suma (11,s) ;
    zbior wynik , E ;
    wynik = C + D ;
    E = C ;
    E+=D ;
    if ( wynik!=suma || E!= suma)
    {
        return false ;
    } else
    {
        return true ;
    }
}
bool testroznica()
{
    float r[] = { 2,3,4,6,7,8} ;
    zbior roznica( 6,r ) ;
    zbior wynik,E ;
    wynik = C - D ;
    E = C ;
    E-=D ;
    if ( wynik != roznica || E != roznica )
    {
        return false ;
    }else
    {
        return true ;
    }
}
bool testprzeciecie()
{
    float p[] = {1,5} ;
    zbior przeciecie( 2,p ) ;
    zbior wynik,E ;
    wynik = C*D ;
    E = C ;
    E*=D ;
    if ( wynik != przeciecie || E != przeciecie )
    {
        return false ;
    }else
    {
        return true ;
    }
}


