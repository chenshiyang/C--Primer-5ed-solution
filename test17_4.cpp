#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <string>

#include "test16_62_Sales_data.h"

using namespace std;

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator,
    vector<Sales_data>::const_iterator> matches;

vector<matches> find_book(const vector<vector<Sales_data>> &files, const string &book) {
    vector<matches> ret;
    for(auto itr = files.cbegin(); itr != files.cend(); ++ itr) {
        auto found = equal_range(itr -> cbegin(), itr -> cend(), book, compareIsbn);
        if(found.first != found.second) {
            ret.push_back(make_tuple(itr - files.cbegin(), found.first, found.second));
        }
    }
    return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files) {
    string s;
    while(in >> s) {
        auto found = find_book(files, s);
        if(found.empty()) {
            os << s << " is not found in any stores" << endl;
        }
        for(const auto &store : found) {
            os << "store: " << get<0>(store) << " sales: "
            << accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
        }
    }
}

int main() {
    vector<Sales_data> store1 = {{"book1", 2, 30.0}, {"book2", 1, 15.0}, {"book2", 2, 15.0}, {"book4", 5, 20.0}};
    vector<Sales_data> store2 = {{"book1", 1, 30.0}, {"book3", 6, 12.0}, {"book4", 1, 20.0}};
    vector<vector<Sales_data>> files = {store1, store2};
    reportResults(cin, cout, files);

    return 0;
}
