#ifndef STATEMENT_H
#define STATEMENT_H

#include <QString>
class Customer;
class Rental;

class Statement
{
public:
	Statement(const Customer* c) : customer(c) {}
	virtual ~Statement() {}

	QString toString() const;

protected:
	virtual QString printHeader () const = 0;
	virtual QString printSummary() const = 0;
	virtual QString printRental(const Rental& rental) const = 0;

protected:
	const Customer* customer;
};

class TextStatement : public Statement
{
public:
	TextStatement(const Customer* c) : Statement(c) {}

protected:
	virtual QString printHeader () const;
	virtual QString printSummary() const;
	virtual QString printRental(const Rental& rental) const;
};

class HTMLStatement : public Statement
{
public:
	HTMLStatement(const Customer* c) : Statement(c) {}

protected:
	virtual QString printHeader () const;
	virtual QString printSummary() const;
	virtual QString printRental(const Rental& rental) const;
};

#endif // PRINTER_H
