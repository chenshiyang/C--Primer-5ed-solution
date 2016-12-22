#ifndef TEST16_21_DEBUGDELETE_H
#define TEST16_21_DEBUGDELETE_H

#include <iostream>
#include <string>
using std::ostream;

class DebugDelete {
public:
    DebugDelete(ostream &s = std::cerr) : os(s) { }

    template <typename T> void operator()(T *p) {
        os << "Deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    ostream &os;
};
#endif // TEST16_21_DEBUGDELETE_H
