#ifndef TEST14_6_SALES_DATA_H
#define TEST14_6_SALES_DATA_H
#include<iostream>
#include<string>

class Sales_data {

    //overload << , test 14.6
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    //over load >>, test 14.9
    friend std::istream& operator>>(std::istream&, Sales_data&);

    //overload - , test 14.13
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

    //overload -=, test 14.13
    friend Sales_data operator-(const Sales_data&, const Sales_data&);

    friend bool operator==(const Sales_data&, const Sales_data&);

    friend bool operator!=(const Sales_data&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}

    //member functions
    std::string isbn() const { return bookNo;}
    //overload +=, test 14.20
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);
    //overload =, test 14.22
    Sales_data& operator=(const std::string&);

    //conversion operator test 14.45
    operator double() const;
    operator std::string() const;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;
};

inline double Sales_data::avg_price() const {
    if(units_sold != 0 ) {
        return revenue / units_sold;
    } else {
        return revenue;
    }
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if(is) {
        item.revenue = item.units_sold * price;
    } else {
        item = Sales_data();
    }
    return is;
}

Sales_data operator+(const Sales_data &item1, const Sales_data &item2) {
    Sales_data sum = item1;
    sum += item2; //  call operator+=
    return sum;
}

//users need to make sure both the isbn is the same.
Sales_data& Sales_data::operator+=(const Sales_data &item) {
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;
}

Sales_data operator-(const Sales_data &item1, const Sales_data &item2) {
    Sales_data remain = item1;
    remain -= item2;
    return remain;
}

//users need to make sure: 1. isbn is the same, this.units_sold >= item.units_sold
Sales_data& Sales_data::operator-=(const Sales_data &item) {
    units_sold -= item.units_sold;
    revenue -= item.revenue;
    return *this;
}

bool operator==(const Sales_data &item1, const Sales_data &item2) {
    return item1.isbn() == item2.isbn() &&
    item1.units_sold == item2.units_sold &&
    item1.revenue == item2.revenue;
}

bool operator!=(const Sales_data &item1, const Sales_data &item2) {
    return !(item1 == item2);
}

Sales_data& Sales_data::operator=(const std::string &s) {
    if(isbn() != s) {
        bookNo = s;
        units_sold = 0;
        revenue = 0.0;
    }
    return *this;
}

Sales_data::operator std::string() const {
    return bookNo;
}

Sales_data::operator double() const {
    return revenue;
}
#endif // TEST14_6_SALES_DATA_H
