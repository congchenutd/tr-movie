#ifndef MOVIE_H
#define MOVIE_H

#include <QString>

class Price;

class Movie
{
public:
	typedef enum {REGULAR_MOVIE, NEW_RELEASE_MOVIE, CHILDREN_MOVIE} MovieType;

public:
	Movie(const QString& n, MovieType t);

	QString   getTitle() const { return title; }
	MovieType getType()  const;

	void setTitle(const QString& t) { title = t; }
	void setType(MovieType t);

	double getCharge(int daysRented) const;
	int    getPoints(int daysRented) const;

private:
	QString title;
	Price*  price;
};

#endif
