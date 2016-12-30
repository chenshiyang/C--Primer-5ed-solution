#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include "test19_19_Sales_data.h"

using namespace std;
using std::placeholders::_1;

bool higher_than(const Sales_data& sd, double price) {
    return sd.avg_price() > price;
}

void find_first_higher_than(vector<Sales_data> &svec, double price) {
    cout << *find_if(svec.cbegin(), svec.cend(), bind(higher_than, _1, price)) << endl;
}

int main() {
    Sales_data sd1("book1", 4, 30.0);
    Sales_data sd2("book2", 1, 60.0);
    Sales_data sd3("book3", 5, 20.0);
    vector<Sales_data> svec = {sd1, sd2, sd3};
    find_first_higher_than(svec, 50.0);
    return 0;
}
