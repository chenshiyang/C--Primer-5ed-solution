#include<iostream>
#include<string>

using namespace std;

class Sales_data {
public:
    Sales_data() = default;

    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p * n) {}

    Sales_data(const string &s) : bookNo(s) {}

    Sales_data(istream&);

    string isbn() const {
        return bookNo;
    }

    Sales_data &combine(const Sales_data&);

    void print() const {
//        string s;
        cout << bookNo << " " << units_sold << " " << revenue << endl;
//        return s + this->bookNo + " " + units_sold + " " + revenue + "\n";
    }

private:
    double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data sd1 = Sales_data("C++ Primer");
//    cout << sd1.bookNo << " " << sd1.units_sold << " " << sd1.revenue << endl;
    sd1.print();
    return 0;
}
