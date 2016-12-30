#include <iostream>

using namespace std;

class Class {
public:
    Class() {
        cout << "Class()" << endl;
    }
};

class Base : public Class {
public:
    Base() {
        cout << "Base()" << endl;
    }
};

class D1 : virtual public Base {
public:
    D1() {
        cout << "D1()" << endl;
    }
};

class D2 : virtual public Base {
public:
    D2() {
        cout << "D2()" << endl;
    }
};

class MI : public D1, public D2 {
public:
    MI() {
        cout << "MI()" << endl;
    }
};

class Final : public MI, public Class {
public:
    Final() {
        cout << "Final()" << endl;
    }
};

int main() {
    //(a)(b)
    Final f;

    //(c)
    Base *pb = nullptr;
    Class *pc = nullptr;
    MI *pmi = nullptr;
    D2 *pd2 = nullptr;
//    pb = new Class;//invalid conversion
//    pc = new Final;//'Class' is an ambiguous base of 'Final'
//    pmi = pb;//invalid conversion
//    pd2 = pmi;//ok
    return 0;
}
