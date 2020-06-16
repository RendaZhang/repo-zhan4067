## Lab Session 9: Refactoring Exercise
### Due date: This is an in-lab exercise and must be done in the lab unless you have a preapproved absence.

Purpose: In this lab, you will learn more about refactoring so that you will understand how to do the refactoring for iteration 3. This lab is based on a refactoring exercise developed by Martin Fowler.

Special Instructions: You have to show a TA your work at the point in this lab where it states to show the TA. You will get full credit for the lab at that point. You do not need to turn anything in. You cannot complete the work outside of the lab and get credit.

##### The Starting Code:
 This program calculates and prints a statement of a customer's charges at a video store.  Based on the information that the program gathers, the movies a customer rents and for how long, the charges are computed for the customer and a statement is created.  There are three types of movies that a customer may rent (i.e. children's, regular, and new releases). In addition to calculating the rental charges, the statement also calculates the frequent rental points.  

Movie: The movie class represents a movie in the rental store's movie collection.
````
    // Movie.h
    #ifndef MOVIE_H
    #define MOVIE_H
    #include <string>

    class Movie {
    public:
      static const int CHILDRENS   = 2;
      static const int REGULAR     = 0;
      static const int NEW_RELEASE = 1;

      Movie( const std::string& title, int priceCode = REGULAR );

      int getPriceCode() const;
      void setPriceCode( int arg );
      std::string getTitle() const;

    private:
      std::string _title;
      int _priceCode;
    };

    inline Movie::Movie( const std::string& title, int priceCode )
      : _title( title ), _priceCode( priceCode ) {}

    inline int Movie::getPriceCode() const { return _priceCode; }

    inline void Movie::setPriceCode( int arg ) { _priceCode = arg; }

    inline std::string Movie::getTitle() const { return _title; }

    #endif // MOVIE_H
````
````
    // Movie.cpp
    #include "Movie.h"

    const int Movie::CHILDRENS;
    const int Movie::REGULAR;
    const int Movie::NEW_RELEASE;
````

Rental:  The rental class represents a customer renting a movie.
````
    // Rental.h
    #ifndef RENTAL_H
    #define RENTAL_H
    #include "Movie.h"

    class Rental {
    public:
      Rental( const Movie& movie, int daysRented );

      int getDaysRented() const;
      const Movie& getMovie() const;

    private:
      Movie _movie;
      int _daysRented;
    };

    inline Rental::Rental( const Movie& movie, int daysRented )
      : _movie( movie ), _daysRented( daysRented ) {}

    inline int Rental::getDaysRented() const { return _daysRented; }

    inline const Movie& Rental::getMovie() const { return _movie; }

    #endif // RENTAL_H
````

Customer:  
The customer class represents the customer of the store. Like the other classes it has data and accessors.  It also has the method that produces a statement.
````
    // Customer.h
    #ifndef CUSTOMER_H
    #define CUSTOMER_H
    #include <string>
    #include <vector>
    #include "Rental.h"

    class Customer {
    public:
      Customer();
      explicit Customer( const std::string& name );

      void addRental( const Rental& arg );
      std::string getName() const;
      std::string statement();

    private:
      std::string _name;
      std::vector< Rental > _rentals;
    };

    inline Customer::Customer() {}

    inline Customer::Customer( const std::string& name )
      : _name( name ) {}

    inline void Customer::addRental( const Rental& arg ) { _rentals.push_back( arg ); }

    inline std::string Customer::getName() const { return _name; }

    #endif // CUSTOMER_H
````
````
    // Customer.cpp
    #include <sstream>
    #include <vector>
    #include "Customer.h"

    using std::ostringstream;
    using std::vector;

    string Customer::statement() {
       double totalAmount = 0;
       int frequentRenterPoints = 0;
       vector< Rental >::iterator iter = _rentals.begin();
       vector< Rental >::iterator iter_end = _rentals.end();
       ostringstream result;

      result << "Rental Record for " << getName() << "\n";
      for ( ; iter != iter_end; ++iter ) {
          double thisAmount = 0;
          Rental each = *iter;

          // determine amounts for each line
         switch ( each.getMovie().getPriceCode() ) {
            case Movie::REGULAR:
               thisAmount += 2;
               if ( each.getDaysRented() > 2 )
                  thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
               break;
            case Movie::NEW_RELEASE:
               thisAmount += each.getDaysRented() * 3;
               break;
            case Movie::CHILDRENS:
               thisAmount += 1.5;
               if ( each.getDaysRented() > 3 )
                  thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
               break;
         }

         // add frequent renter points
         frequentRenterPoints++;

         // add bonus for a two day new release rental
         if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 )  
           frequentRenterPoints++;

         // show figures for this rental
         result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << "\n";
        totalAmount += thisAmount;
      }
      // add footer lines
      result << "Amount owed is " << totalAmount << "\n";
      result << "You earned " << frequentRenterPoints
         << " frequent renter points";
      return result.str();  
    }
````

#### Questions to Ponder (not to submit)
1. Is this well designed and does it follow OOP programming concepts?
2. Focusing in on the Customer class, what is your reaction to the _statement_ method?
3. Does this _statement_ method code allow for changes to be made to the system readily? What would need to change to display via the web using HTML and be fully buzzword compliant?  Would you copy and paste the code to another method name and create a "similar" method with slightly different functionality? _No._ Is this good programming? _No._ Think about how many places you would have to change code if you made, for example, changes in the charging rules. You would have to fix both the _statement_ and the _htmlstatement_ methods.  What happens if you forget?

<hr>
Good rule to follow:  "When you find you have to add a feature to a program, and the program's code is not structured in a convenient way to add the feature, first refactor the program to make it easy to add the feature, then add the feature." [Martin Fowler]
<hr>

#### First Step in Refactoring
The first step is the same for all refactoring. You need to have a solid set of tests built so you can test your changes as you make them. You do not want to introduce bugs into working code through the refactoring. We have talked about the need for unit tests and now you will benefit from developing testing suites from the start. How can you ensure your changes still work? _You test!_

For this exercise, you will need to run the code prior to the refactoring so you understand what it does. Come up with a couple of good test cases and write them down with the correct output. Of course the best way to develop unit tests is in a formal testing framework, but simply noting the expected answer will be sufficient for our purpose here. Save your test cases and results so you can retest after you refactor. We will be focusing on the _statement_ method first.

####  Getting Started on The Refactoring: Redistributing the Statement Method
Look at how long that _statement_ method is. These types of long methods cry out for decomposing into smaller pieces. Smaller pieces are more easily managed.  Our aim for this statement method is to make it easier to write an HTML statement method without having so much duplication of code.  

##### The Extract Method

1) The _Extract Method_ of refactoring is finding a logical grouping of code and make it into its own method/helper function. We will focus on the _switch_ statement in the _statement_ method.  

````
for ( ; iter != iter_end; ++iter ) {
   double thisAmount = 0;
   Rental each = *iter;

   // determine amounts for each line__
   switch ( each.getMovie().getPriceCode() ) {
     case Movie::REGULAR:
       thisAmount += 2;
       if ( each.getDaysRented() > 2 )
         thisAmount += ( each.getDaysRented() - 2 ) * 1.5;
       break;
     case Movie::NEW_RELEASE:
       thisAmount += each.getDaysRented() * 3;
       break;
     case Movie::CHILDRENS:
       thisAmount += 1.5;
       if ( each.getDaysRented() > 3 )
         thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
       break;
   }

   // add frequent renter points
   frequentRenterPoints++;
   // add bonus for a two day new release rental
   if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
        && each.getDaysRented() > 1 ) frequentRenterPoints++;

   // show figures for this rental
   result << "\t" << each.getMovie().getTitle() << "\t"
          << thisAmount << "\n";
   totalAmount += thisAmount;
 }
 ````
2) Look for variables in the code segment that are local in scope.  This segment of code uses _each_ and _thisAmount_.  Notice that _each_ is not modified but _thisAmount_ is modified.  We must take special care in handling modified variables.  If there is only one, you can return that from your new method. _ThisAmount_ is initialized to 0 each time around the loop and is then modified only in the switch statement, thus this will be the return value for the new method.  

The new code looks like:
````
// Customer.h
...
class Customer {
...
private:
  std::string _name;
  std::vector< Rental > _rentals;
  double amountFor( const Rental& each ) const;
};

// Customer.cpp
...
string Customer::statement()
{
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  ostringstream result;
  result << "Rental Record for " << getName() << "\n";
  for ( ; iter != iter_end; ++iter ) {
    double thisAmount = 0;
    Rental each = *iter;

    thisAmount = amountFor( each );

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << "\n";
    totalAmount += thisAmount;
  }
  // add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";
  return result.str();
}

double Customer::amountFor( const Rental& each ) const
{
  double thisAmount = 0;
  switch ( each.getMovie().getPriceCode() ) {
    case Movie::REGULAR:
      thisAmount += 2;
      if ( each.getDaysRented() > 2 )
        thisAmount += ( each.getDaysRented() - 2 ) * 1.5;
      break;
    case Movie::NEW_RELEASE:
      thisAmount += each.getDaysRented() * 3;
      break;
    case Movie::CHILDRENS:
      thisAmount += 1.5;
      if ( each.getDaysRented() > 3 )
        thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
      break;
  }
  return thisAmount;
}
````
##### Variable Renaming

Now that we have refactored a chunk of code, we can work on the variable names.  Some of the variable names can be changed to have more meaning.  Lets change the variable _each_ to _aRental_ and _thisAmount_ to _result_.  Renaming is important.  Good code should communicate what you are doing clearly and variable names are important!
````
double Customer::amountFor( const Rental& aRental ) const
{
  double result = 0;
  switch ( aRental.getMovie().getPriceCode() ) {
    case Movie::REGULAR:
      result += 2;
      if ( aRental.getDaysRented() > 2 )
        result += ( aRental.getDaysRented() - 2 ) * 1.5;
      break;
    case Movie::NEW_RELEASE:
      result += aRental.getDaysRented() * 3;
      break;
    case Movie::CHILDRENS:
      result += 1.5;
      if ( aRental.getDaysRented() > 3 )
        result += ( aRental.getDaysRented() - 3 ) * 1.5;
      break;
  }
  return result;
}
````

#### Class Cohesion

Now lets look at the _amountFor_ method.  It uses information about the rental but not the customer.  Maybe, the method is in the wrong object.  A method should be in the object whose data it uses.  

1) The _amountFor_ method should be moved to rental.  Copy the code over to the rental first, adjust it to fit into its new home, and compile. Then take it out of Customer.h and Customer.cpp.

````
// Rental.h
...
class Rental {
public:
...
  double getCharge() const;
...

// Rental.cpp
#include "Rental.h"

double Rental::getCharge() const {
  double result = 0;
  switch ( getMovie().getPriceCode() ) {
    case Movie::REGULAR:
      result += 2;
      if ( getDaysRented() > 2 )
        result += ( getDaysRented() - 2 ) * 1.5 ;
      break;
    case Movie::NEW_RELEASE:
      result += getDaysRented() * 3;
      break;
    case Movie::CHILDRENS:
      result += 1.5;
      if ( getDaysRented() > 3 )
        result += ( getDaysRented() - 3 ) * 1.5;
      break;
  }
  return result;
}
````

2) To make sure the method works, replace the body of Customer::amountFor to delegate to the new method.

````
// Customer.cpp
...
double Customer::
amountFor( const Rental& aRental ) const
{
  return aRental.getCharge();
}
````
3) Once tested, make sure you find every reference to the old method and adjust the reference to use the new method.  Using cscope can help manage multiple "finds." Once you have changed everyone, remove the old method. (Note: look up cscope if you have never heard of it - it can come in handy!)

````
// Customer.cpp
...
string Customer::statement()
{
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  ostringstream result;
  result << "Rental Record for " << getName() << "\n";

  for ( ; iter != iter_end; ++iter ) {
    double thisAmount = 0;
    Rental each = *iter;

    thisAmount = each.getCharge()

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << thisAmount << "\n";
    totalAmount += thisAmount;
  }
  // add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";
  return result.str();
}
````
4)  Now we can see that _thisAmount_ is redundant because we set it to the result of _each.getCharge_ and do not change it again.  Eliminate _thisAmount_ and instead use _each.getCharge_.

````
// Customer.cpp
...
string Customer::statement()
{
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  ostringstream result;
  result << "Rental Record for " << getName() << "\n";
  for ( ; iter != iter_end; ++iter ) {
    Rental each = *iter;

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
         && each.getDaysRented() > 1 ) frequentRenterPoints++;

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << each.getCharge() << "\n";
    totalAmount += each.getCharge();
  }
  // add footer lines
  result << "Amount owed is " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";
  return result.str();
}
````

>Don't forget to compile and test!  Small steps and testing along the way will ensure your refactoring does not break the program.

#### Removing Temporary Variables

Temporary variables can cause problems.  In the _statement_ method we have two temporary variables,  _totalAmount_ and _frequentRenterPoints_.  Use queries to fix these.  What will the code look like now?  (Change your own code and don't peek at the following code until you come up with your own solution.)










* First...

````
// Customer.h
...
class Customer {
...
private:
...
  double getTotalCharge();
};

// Customer.cpp
...
string Customer::statement()
{
  int frequentRenterPoints = 0;
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  ostringstream result;
  result << "Rental Record for " << getName() << "\n";
  for ( ; iter != iter_end; ++iter ) {
    Rental each = *iter;
    frequentRenterPoints += each.getFrequentRenterPoints();

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << each.getCharge() << "\n";
  }
  // add footer lines
  result << "Amount owed is " << getTotalCharge() << "\n";
  result << "You earned " << frequentRenterPoints
         << " frequent renter points";
  return result.str();
}

double Customer::getTotalCharge()
{
  double result = 0;
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  for ( ; iter != iter_end; ++iter ) {
    Rental each = \*iter;
    result += each.getCharge();
  }
  return result;
}

````

* Second ...

````
// Customer.h
...
class Customer {
...
private:
...
  int getTotalFrequentRenterPoints();
};

// Customer.cpp
...
string Customer::statement()
{
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  ostringstream result;
  result << "Rental Record for " << getName() << "\n";
  for ( ; iter != iter_end; ++iter ) {
    Rental each = *iter;

    // show figures for this rental
    result << "\t" << each.getMovie().getTitle() << "\t"
           << each.getCharge() << "\n";
  }
  // add footer lines
  result << "Amount owed is " << getTotalCharge() << "\n";
  result << "You earned " << getTotalFrequentRenterPoints()
         << " frequent renter points";
  return result.str();
}

int Customer::getTotalFrequentRenterPoints()
{
  int result = 0;
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  for ( ; iter != iter_end; ++iter ) {
    Rental each = \*iter;
    result += each.getFrequentRenterPoints();
  }
  return result;
}
````
* First: replace total_Amount with a charge method in Customer
* Second: fix the frequentRenterPoints

##### Refactor Complete. Code Ready for Functional Modification.

Remember that _refactoring_ does not mean that you are changing functionality -- only how the code is structured. You might follow the motto "If it ain't broke, don't fix it." This is reasonable advice, and refactoring IS changing code so it runs the risk of adding in bugs. However, if you are in the process of modifying code to enhance or modify functionality, take the opportunity to refactor to make those changes (and future changes) easier.

<hr>
**Show the TA that you have completed this part to receive credit for this lab. Have your code up on the screen and demonstrate that it compiles. You should make it at least this far. Keep going if there is more time left ...**
<hr>

1) Modify the code to be viewable via the web ...

````
// Customer.h
...
class Customer {
public:
...
  std::string htmlStatement();
...

// Customer.cpp
...
string Customer::htmlStatement()
{
  vector< Rental >::iterator iter = _rentals.begin();
  vector< Rental >::iterator iter_end = _rentals.end();
  ostringstream result;
  result << "<H1>Rentals for <EM>" << getName() << "</EM></H1><P>\n";
  for ( ; iter != iter_end; ++iter ) {
    Rental each = *iter;
    // show figures for each rental
    result << each.getMovie().getTitle() << ": "
           << each.getCharge() << "<BR>\n";
  }
  // add footer lines
  result << "<P>You owe <EM>" << getTotalCharge() << "</EM><P>\n";
  result << "On this rental you earned <EM>"
         << getTotalFrequentRenterPoints()
         << "</EM> frequent renter points<P>";
  return result.str();
}
````
2)  Replace the Conditional Logic on Price Code with Polymorphism:  It is not a good idea to use a _switch_ statement based on another object. If you must use a _switch_, it should be on your own data, not on someone else's.

* First, move the _getCharge_ method from rental into movie.  Notice we had to add the length of the rental as an input parameter.  Compile and change rental to use the new method.

````
// Movie.h
...
class Movie {
public:
...
  double getCharge( int daysRented ) const;
...

// Movie.cpp
...
double Movie::
getCharge( int daysRented ) const
{
  double result = 0;
  switch ( getPriceCode() ) {
    case Movie::REGULAR:
      result += 2;
      if ( daysRented > 2 )
        result += ( daysRented - 2 ) * 1.5 ;
      break;
    case Movie::NEW_RELEASE:
      result += daysRented * 3;
      break;
    case Movie::CHILDRENS:
      result += 1.5;
      if ( daysRented > 3 )
        result += ( daysRented - 3 ) * 1.5;
      break;
  }
  return result;
}

// Rental.cpp
...
double Rental::move
getCharge() const
{
  return _movie.getCharge( _daysRented );
}

````
* Second. Now do the same with the frequent renter point calculation.

Compile and retest. Does it still work?  It should and you have a great start on refactoring this code.  There is more you can do but this is enough to get your rolling.

Be sure to sign in today to get credit for the lab!

##### Refactoring Resource

Refactoring, Improving the Design of Existing Code by Martin Fowler, with contributions by Kent Beck, John Brant, William Opdyke, and Don Roberts, Chapter 1 (http://jczeus.com/refac_cpp.html)
