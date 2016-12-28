#include <iostream>

namespace Exercise {
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;
//using namespace Exercise;
//using Exercise::ivar;
//using Exercise::dvar;
//using Exercise::limit;


void manip() {
//    using namespace Exercise;
using Exercise::ivar;
using Exercise::dvar;
using Exercise::limit;
    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ ivar;
    ++ ::ivar;
}

int main() {
    return 0;
}
