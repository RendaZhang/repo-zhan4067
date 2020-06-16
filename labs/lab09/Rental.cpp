#include "Rental.h"

double Rental::getFrequentRenterPoints() const {
  return 1;
}

double Rental::getCharge() const
{
  return _movie.getCharge( _daysRented );
}
