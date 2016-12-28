#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

void exercise1(int *b, int *e) {
    try {
        vector<int> v(b, e);
        int *p = new int[v.size()];
        ifstream in("ins");
        throw p;
    } catch(int *p) {
        delete[] p;
    }
}

void exercise2(int *b, int *e) {
    try {
        vector<int> v(b, e);
        unique_ptr<int[]> p(new int[v.size()]);
        ifstream in("ins");
    } catch(...) {

    }
}

void exercise3(int *b, int *e) {
    vector<int> v(b, e);
    int* p = new int[v.size()];
    ifstream in("ins");
    try {
        throw p;
    } catch(...) {
        delete[] p;
    }
    delete[] p;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int *b = std::begin(a), *e = std::end(a);
    exercise1(b, e);
    exercise2(b, e);
    exercise3(b, e);
    return 0;
}
