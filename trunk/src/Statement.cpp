#include "Statement.h"
#include "Customer.h"
#include "Movie.h"
#include <QTextStream>

QString Statement::toString() const
{
	// Header
	QString result;
	QTextStream os(&result);
	os << printHeader();

	// Rentals
	foreach(Rental rental, customer->getRentals())
		os << printRental(rental);

	// Summary
	os << printSummary();
	return result;
}

////////////////////////////////////////////////////////////////////////
QString TextStatement::printHeader() const
{
	QString result;
	QTextStream os(&result);
	os << "Customer name: " << customer->getName() << "\n";
	return result;
}

QString TextStatement::printRental(const Rental& rental) const
{
	QString result;
	QTextStream os(&result);
	os << "    " << rental.getMovie()->getTitle()
	   << ": "   << rental.getCharge() << "\n";
	return result;
}

QString TextStatement::printSummary() const
{
	QString result;
	QTextStream os(&result);
	os << "Total amount: " << customer->getTotalAmount() << "\n";
	os << "Total points: " << customer->getTotalPoints() << "\n";
	return result;
}

////////////////////////////////////////////////////////////////////////
QString HTMLStatement::printHeader() const
{
	QString result;
	QTextStream os(&result);
	os << "<HTML>\n";
	os << "<P>Customer name: " << customer->getName() << "</P>\n";
	return result;
}

QString HTMLStatement::printRental(const Rental& rental) const
{
	QString result;
	QTextStream os(&result);
	os << "<P>&nbsp;&nbsp;&nbsp;&nbsp;" << rental.getMovie()->getTitle()
	   << ": "                          << rental.getCharge() << "</P>\n";
	return result;
}

QString HTMLStatement::printSummary() const
{
	QString result;
	QTextStream os(&result);
	os << "<P>Total amount: " << customer->getTotalAmount() << "</P>\n";
	os << "<P>Total points: " << customer->getTotalPoints() << "</P>\n";
	os << "</HTML>\n";
	return result;
}


