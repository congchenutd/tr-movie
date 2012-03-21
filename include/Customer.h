#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QString>
#include <QList>
#include "Rental.h"

class Customer
{
public:
	Customer(const QString& n);

	QString getName() const { return name; }
	void setName(const QString& n) { name = n; }
	void addRental(const Rental& rental);
	QList<Rental> getRentals() const{ return rentals; }

	double getTotalAmount() const;
	double getTotalPoints() const;

	// come comment
	QString getStatement() const;

private:
	QString       name;
	QList<Rental> rentals;
};

#endif
