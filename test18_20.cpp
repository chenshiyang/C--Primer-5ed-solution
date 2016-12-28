#include <iostream>

using namespace std;

namespace primerLib {
    void compute() {
        cout << "primerLib::compute()" << endl;
    }

//    void compute(const void *p) {
//        cout << "primerLib::compute(const void *)" << endl;
//    }
}



void compute(int i) {
    cout << "::compute(int)" << endl;
}

void compute(double d, double d2 = 3.4) {
    cout << "::compute(double, double = 3.4)" << endl;
}

void compute(char* p1, char* p2 = 0) {
    cout << "::compute(char*, char* = 0)" << endl;
}

void f() {
    using primerLib::compute;
    compute(0);
}

int main() {
    f();
    return 0;
}
