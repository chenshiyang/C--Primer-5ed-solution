#ifndef TEST15_15_QUOTE_H
#define TEST15_15_QUOTE_H

#include <iostream>
#include <string>
#include <utility>
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

    //copy constructor, required by test 15.26
    DiscQuote(const DiscQuote &dq) : Quote(dq), quantity(dq.quantity), discount(dq.discount) {
        cout << "DiscQuote(const DiscQuote&) copy constructor is called" << endl;
    }

    //copy assignment operator, required by test 15.26
    DiscQuote& operator=(const DiscQuote& dq) {
        Quote::operator=(dq);
        quantity = dq.quantity;
        discount = dq.discount;
        cout << "DiscQuote copy assignment operator= is called" << endl;
        return *this;
    }

    //descructor required by test 15.26
    ~DiscQuote() {
        cout << "~DiscQuote() is called" << endl;
    }
    //pure virtual function
    virtual double net_price(size_t) const = 0;

protected:
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

    //copy constructor, required by test 15.26
    BulkQuote(const BulkQuote &bq) : DiscQuote(bq) {
        cout << "BulkQuote(const BulkQuote&) copy constructor is called" << endl;
    }

    //copy assignment operator, required by test 15.26
    BulkQuote& operator=(const BulkQuote &bq) {
        DiscQuote::operator=(bq);
        cout << "BulkQuote copy assignment operator= is called" << endl;
        return *this;
    }

    //descructor required by test 15.26
    ~BulkQuote() {
        cout << "~BulkQuote() is called" << endl;
    }

    double net_price(size_t n) const  {
        if(n >= quantity) {
            return price * n * (1 - discount);
        } else {
            return price * n;
        }
    }

    //required by test 15.30
    BulkQuote* clone() const & {
        return new BulkQuote(*this);
    }

    BulkQuote* clone() && {
        return new BulkQuote(std::move(*this));
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

    //copy constructor, required by test 15.26
    LimitQuote(const LimitQuote &lq) : DiscQuote(lq) {
        cout << "LimitQuote(const LimitQuote&) copy constructor is called" << endl;
    }

    //copy assignment operator, required by test 15.26
    LimitQuote& operator=(const LimitQuote &lq) {
        DiscQuote::operator=(lq);
        cout << "LimitQuote copy assignment operator= is called" << endl;
        return *this;
    }

    //destructor required by test 15.26
    ~LimitQuote() {
        cout << "~LimitQuote() is called" << endl;
    }

    double net_price(size_t n) const {
        if(n <= quantity) {
            return (1 - discount) * n * price;
        } else {
            return quantity * price * (1 - discount) + (n - quantity) * price;
        }
    }
};

#endif // TEST15_15_QUOTE_H
