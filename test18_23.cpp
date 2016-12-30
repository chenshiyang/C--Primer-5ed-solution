#include <iostream>

using namespace std;

class A {
public:
    A() {
        cout << "A()" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "B()" << endl;
    }
};

class C : public B {
public:
    C() {
        cout << "C()" << endl;
    }
};

class X {
public:
    X() {
        cout << "X()" << endl;
    }
};

class Y {
public:
    Y() {
        cout << "Y()" << endl;
    }
};

class Z : public X, public Y {
public:
    Z() {
        cout << "Z()" << endl;
    }
};

class MI : public C, public Z {
public:
    MI() {
        cout << "MI()" << endl;
    }
};

class D : public X, public C {
public:
    D() {
        cout << "D()" << endl;
    }
};

int main() {
    D* pd = new D;
    X *px = pd;
    A *pa = pd;
    B *pb = pd;
    C *pc = pd;
    delete pc;
    delete pb;
    delete pa;
    delete pd;
    delete px;


}

