#include <iostream>
#include <unordered_set>
#include <string>
#include "test16_62_Sales_data.h"

using namespace std;



int main() {
    unordered_set<Sales_data> sdSet;
    sdSet.insert(Sales_data("book1", 2, 30.0));
    sdSet.insert(Sales_data("book2", 3, 30.0));
    sdSet.insert(Sales_data("book1", 1, 30.0));
    sdSet.insert(Sales_data("book1", 2, 30.0));

    for(auto i : sdSet) {//notice, the result is unordered.
        cout << i << endl;
    }

    return 0;
}

