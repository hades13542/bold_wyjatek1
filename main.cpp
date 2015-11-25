/** 
 * Prosze napisac  klase wyjatkow bexc i pomocne funkcje do ich obslugi
 * UWAGA: Nie nalezy zmieniac tego pliku ani o jedna linie bo inaczej makro 
 * __LINE__ zostanie ustawione na inne wartości.
 * Kompilowac do pliku b z opcjami -Wall -g
 **/

#include <iostream>
#include <stdexcept>
#include "exc.h"

const char* itoa(int arg) {
  const int bufferSize=32;
  static char buffer[bufferSize];
  snprintf(buffer, bufferSize, "%d", arg);
  return buffer;
}

void f1() {
  throw std::runtime_error(std::string("problem w f1, linia: ")+itoa(__LINE__));
}

void f2() {
  try {
    f1();
  } catch(...) {
    exc::handler("obsluga glebszego wyjatku w f2", __LINE__);
  }
}

void f3() {
  try {
    f2();
  } catch(...) {
    exc::handler("obsluga glebszego wyjatku w f3", __LINE__);
  }
}

int main() {
  using namespace std;
  try {
    f3();
    cout << "udalo sie wykonac f3" << endl;
  } catch(const exc::bexc& e) {

    cout << "problem przy wykonaniu f3" << endl;
    cout << "... " << e.message() << " w linii: " << e.codeline() << endl;    
  }
}
/* wynik
... wyjatek podstawowy: problem w f1, linia: 20
... wyjatek bexc: obsluga glebszego wyjatku w f2 w linii: 27
problem przy wykonaniu f3
... obsluga glebszego wyjatku w f3 w linii: 35
 */
