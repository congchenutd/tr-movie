#include "Movie.h"
#include "Price.h"

Movie::Movie(const QString& n, MovieType t)
{
	price = 0;
	setTitle(n);
	setType(t);
}

Movie::MovieType Movie::getType() const {
	return price->getType();               // delegated to PriceStrategy
}

double Movie::getCharge(int daysRented) const {
	return price->getCharge(daysRented);   // delegated to PriceStrategy
}

int Movie::getPoints(int daysRented) const
{
	int points = 1;
	if(getType() == NEW_RELEASE_MOVIE && daysRented > 1)
		points ++;
	return points;
}

void Movie::setType(MovieType t)
{
	if(price != 0)
		delete price;

	switch(t)
	{
	case REGULAR_MOVIE:
		price = new RegularPrice;
		break;
	case NEW_RELEASE_MOVIE:
		price = new NewReleasePrice;
		break;
	case CHILDREN_MOVIE:
		price = new ChildrenPrice;
		break;
	default:
		price = new RegularPrice;
		break;
	}
}

