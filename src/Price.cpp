#include "Price.h"

Movie::MovieType RegularPrice::getType() const {
	return Movie::REGULAR_MOVIE;
}

Movie::MovieType NewReleasePrice::getType() const {
	return Movie::NEW_RELEASE_MOVIE;
}

Movie::MovieType ChildrenPrice::getType() const {
	return Movie::CHILDREN_MOVIE;
}

//
double RegularPrice::getCharge(int daysRented) const
{
	double result = 2.0;
	if(daysRented > 2)
		result += (daysRented-2) * 1.5;
	return result;
}

double NewReleasePrice::getCharge(int daysRented) const {
	return daysRented * 3.0;
}

double ChildrenPrice::getCharge(int daysRented) const
{
	double result = 1.5;
	if(daysRented > 3)
		result += (daysRented-3) * 1.5;
	return result;
}
