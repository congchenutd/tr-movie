#include "Customer.h"
#include "Movie.h"
#include "Statement.h"

Customer::Customer(const QString& n) : name(n) {}

void Customer::addRental(const Rental& rental) {
	rentals << rental;
}

double Customer::getTotalAmount() const
{
	double result = 0.0;
	foreach(Rental rental, rentals)
		result += rental.getCharge();
	return result;
}

double Customer::getTotalPoints() const
{
	int result = 0;
	foreach(Rental rental, rentals)
		result += rental.getPoints();
	return result;
}

QString Customer::getStatement() const {
	return TextStatement(this).toString();
}
