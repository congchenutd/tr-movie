#include "Rental.h"
#include "Movie.h"

Rental::Rental(Movie* m, int days)
{
	movie      = m;
	daysRented = days;
}

double Rental::getCharge() const {
	return getMovie()->getCharge(getDaysRented());
}

int Rental::getPoints() const {
	return getMovie()->getPoints(getDaysRented());
}
