#include <iostream>
#include <string>
#include "test16_62_Sales_data.h"

using namespace std;

int main() {
    Sales_data item("book1", 4, 30.0), *p = &item;
    auto pdata = &Sales_data::isbn;
    cout << (item.*pdata)() << endl;
    cout << (p ->* pdata)() << endl;
    return 0;
}
