#include "Movie.h"
#include "Rental.h"
#include "Customer.h"
#include<string.h>
#include <iostream>

using std::cout;

int main() {
  Movie m1("The Shining", 2);
  Movie m2("Avengers", 0);
  Movie m3("Justice League", 1);

  Rental r1(m1, 10);
  Rental r2(m2, 11);
  Rental r3(m3, 5);

  Customer c1("customer 1");
  Customer c2("customer 2");

  c2.addRental(r1);
  c2.addRental(r2);
  c1.addRental(r1);
  c1.addRental(r3);

  cout << c2.statement() << endl;
  cout << endl;
  cout << c1.statement() << endl;
}
