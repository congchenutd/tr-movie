#ifndef RENTAL_H
#define RENTAL_H

class Movie;

// An association class
class Rental
{
public:
	Rental(Movie* m, int days);

	int    getDaysRented() const { return daysRented; }
	Movie* getMovie()      const { return movie;      }
	double getCharge()     const;
	int    getPoints()     const;

private:
	int    daysRented;
	Movie* movie;
};

#endif
