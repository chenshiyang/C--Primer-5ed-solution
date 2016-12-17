#ifndef TEST15_QUOTE_H
#define TEST15_QUOTE_H

#include <string>
#include <iostream>
#include <utility>

using std::string;
using std::size_t;
using std::ostream;
using std::endl;
using std::cout;

//for test 15.3 15.5 15.6 15.7


class Quote {
public:
    Quote() = default;

    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {
        cout << "Quote(const string&, double&) constructor is called" << endl;
    }

    //copy constructor, required by test 15.26
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
        cout << "Quote(const Quote&) copy constructor is called" << endl;
    }

    //copy assignment operator, required by test 15.26
    Quote& operator=(const Quote& q) {
        bookNo = q.bookNo;
        price = q.price;
        cout << "Quote copy assignment operator is called" << endl;
        return *this;
    }

    virtual ~Quote() {
        cout << "~Quote() is called" << endl;
    };

    string isbn() const { return bookNo; }

    virtual double net_price(size_t n) const {
        return price * n;
    }

    //required by test 15.11
    virtual void debug() const {
        cout << "Quote.debug() : bookNo: " << bookNo << " | price: " << price << endl;
    }

    //required by test 15.30
    virtual Quote* clone() const & {
        return new Quote(*this);
    }

    virtual Quote* clone() && {
        return new Quote(std::move(*this));
    }

private:
    string bookNo;

protected:
    double price = 0.0;

};

double print_total(ostream& os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn()
    << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}


///////////////////////////
// Definition of Bulk_quote
///////////////////////////


class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;

    Bulk_quote(const string &book, double p, size_t qty, double disc) :
        Quote(book, p), min_qty(qty), discount(disc) {
            cout << "Builk_quote(...) constructor is called" << endl;
    }

    double net_price(size_t) const override;

    //required by test 15.11
    void debug() const {
        cout << "Bulk_quote.debug: bookNo: " << isbn() << " | " << " price: " << price
        << " | min_quantity: " << min_qty << " | discount: " << discount << endl;
    }

private:
    double min_qty = 1.0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const {
    if(cnt >= min_qty) {
        return cnt * (1 - discount) * price;
    } else {
        return cnt * price;
    }
}

/////////////////////////////////
// class required by test 15.7
/////////////////////////////////

class Limit_quote : public Quote {
public:
    Limit_quote() = default;

    Limit_quote(const string &book, double p, size_t n, double disc) :
        Quote(book, p), max_qty(n), discount(disc) {
        cout << "Limit_quote(...) constructor is called" << endl;
    }

    double net_price(size_t n) const {
        if(n <= max_qty) {
            return (1 - discount) * n * price;
        } else {
            return max_qty * price * (1 - discount) + (n - max_qty) * price;
        }
    }

    //required by test 15.11
    void debug() const {
        cout << "Limit_quote.debug: bookNo: " << isbn() << " | " << " price: " << price
        << " | max_quantity: " << max_qty << " | discount: " << discount << endl;
    }

private:
    size_t max_qty = 1.0;
    double discount = 0.0;
};


#endif // TEST15_QUOTE_H
