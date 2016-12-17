#ifndef TEST15_15_QUOTE_H
#define TEST15_15_QUOTE_H

#include <iostream>
#include <string>
#include "test15_Quote.h"

using std::string;
using std::size_t;
using std::ostream;
using std::endl;
using std::cout;

////////////////////////////////////////
////// Definition for DiscQuote,  required by test 15.15
////////////////////////////////////////

class DiscQuote : public Quote {
public:
    DiscQuote() = default;

    DiscQuote(const string& book, double p, size_t qty, double disc) :
        Quote(book, p), quantity(qty), discount(disc)
    {
        cout << "DiscQuote(...) constructor is called" << endl;
    }

    //pure virtual function
    virtual double net_price(size_t) const = 0;

private:
    size_t quantity = 0;
    double discount = 0.0;
};

/////////////////////////////////////////////////////////
// Definition for BulkQuote , required by test 15.16
/////////////////////////////////////////////////////////

class BulkQuote : public DiscQuote {
public:
    BulkQuote() = default;
    BulkQuote(const string& book, double p, size_t qty, double disc) :
        DiscQuote(book, p, qty, disc) {
            cout << "BulkQuote(...) constructor is called" << endl;
    }

    double net_price(size_t n) const  {
        if(n >= quantity) {
            return price * n * (1 - discount);
        } else {
            return price * n;
        }
    }
};

/////////////////////////////
// Definition for LimitQuote
/////////////////////////////

class LimitQuote : public DiscQuote {
public:
    LimitQuote() = default;

    LimitQuote(const string &book, double p, size_t qty, double disc) :
        DiscQuote(book, p, qty, disc) {
        cout << "LimitQuote(...) constructor is called" << endl;
    }

    double net_price(size_t n) const {
        if(n <= quantiy) {
            return (1 - discount) * n * price;
        } else {
            return quantity * price * (1 - discount) + (n - quantity) * price;
        }
    }
};

#endif // TEST15_15_QUOTE_H
