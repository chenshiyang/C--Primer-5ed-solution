#ifndef TEST15_13_BASE_H
#define TEST15_13_BASE_H

#include <iostream>
#include <string>

using std::ostream;
using std::string;
using std::endl;

class base {
public:

    base() = default;

    base(const string &s) : basename(s) {}

    string name() {
        cout << "call base.name() " << endl;
        return basename;
    }

    virtual void print(ostream &os) {
        os << "call base.print() " << endl;
        os << basename << endl;
    }

private:
    string basename;
};


class derived : public base {
public:

    derived() = default;

    derived(const string &s, int ii) :
        base(s), i(ii) {}

    void print(ostream &os) {
        os << "call derived.print() " << endl;
        base::print(os);
        os << " " << i << endl;
    }

private:
    int i;
};
#endif // TEST15_13_BASE_H
