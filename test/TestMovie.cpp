#include "Movie.h"
#include "Rental.h"
#include "Customer.h"

#include <QObject>
#include <QtTest/QtTest>

class TestMovie : public QObject
{
	Q_OBJECT

private slots:
	void initTestCase();
	void testGetStatement();

private:
	Movie* movie1;
	Movie* movie2;
	Movie* movie3;
	Customer* customer;
	QString textStatement;
	QString htmlStatement;
};

void TestMovie::initTestCase()
{
	// movies
	movie1 = new Movie("Kong Fu Panda 2", Movie::REGULAR_MOVIE);
	movie2 = new Movie("Toy Story 3",     Movie::CHILDREN_MOVIE);
	movie3 = new Movie("Mission Impossible 4",  Movie::NEW_RELEASE_MOVIE);

	// a customer with 3 rentals
	customer = new Customer("Cong Chen");
	customer->addRental(Rental(movie1, 2));
	customer->addRental(Rental(movie2, 3));
	customer->addRental(Rental(movie3, 4));

	// exptected output
	textStatement = QString("Customer name: Cong Chen\n") +
					"    Kong Fu Panda 2: 2\n" +
					"    Toy Story 3: 1.5\n" +
					"    Mission Impossible 4: 12\n" +
					"Total amount: 15.5\n" +
					"Total points: 4\n";

	htmlStatement = QString("<HTML>\n") +
					"<P>Customer name: Cong Chen</P>\n" +
					"<P>&nbsp;&nbsp;&nbsp;&nbsp;Kong Fu Panda 2: 2</P>\n" +
					"<P>&nbsp;&nbsp;&nbsp;&nbsp;Toy Story 3: 1.5</P>\n" +
					"<P>&nbsp;&nbsp;&nbsp;&nbsp;Mission Impossible 4: 12</P>\n" +
					"<P>Total amount: 15.5</P>\n" +
					"<P>Total points: 4</P>\n" +
					"</HTML>\n";
}

void TestMovie::testGetStatement()
{
	// compare actual output with expected
	QCOMPARE(customer->getStatement(), textStatement);
}

QTEST_APPLESS_MAIN(TestMovie)
#include "TestMovie.moc"



