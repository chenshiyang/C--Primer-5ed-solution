
#include<iostream>
#include<string>
using namespace std;

struct Sales_data {
    string book_no;
    unsigned units_sold{0};
    double revenue{0};
};

int main() {
    Sales_data data1, data2;
    double price = 0;
    cin >> data1.book_no >> data1.units_sold >> price;
    data1.revenue = price * data1.units_sold;

    cin >> data2.book_no >> data2.units_sold >> price;
    data2.revenue = price * data2.units_sold;

    if(data1.book_no == data2.book_no) {
        unsigned totalCount = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.book_no << " " << totalCount << " " << totalRevenue << " ";
        if(totalCount != 0) {
            cout << totalRevenue / totalCount << endl;
        } else {
            cout << "(no sales)" << endl;
        }
        return 0;
    } else {
        cout << "Data must refer to the same book no" << endl;
        return -1;
    }
}
