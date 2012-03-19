#ifndef PRICE_H
#define PRICE_H

#include "Movie.h"

// Price strategies
class Price  
{
public:
	virtual ~Price() {}
	virtual Movie::MovieType getType()                 const = 0;
	virtual double           getCharge(int daysRented) const = 0;
};

class RegularPrice : public Price
{
public:
	virtual Movie::MovieType getType() const;
	virtual double           getCharge(int daysRented) const;
};

class NewReleasePrice : public Price
{
public:
	virtual Movie::MovieType getType() const;
	virtual double           getCharge(int daysRented) const;
};

class ChildrenPrice : public Price
{
public:
	virtual Movie::MovieType getType() const;
	virtual double           getCharge(int daysRented) const;
};

#endif
