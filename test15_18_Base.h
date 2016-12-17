#ifndef TEST15_18_BASE_H
#define TEST15_18_BASE_H

#include <iostream>
#include <string>
using std::cout;

//for test 15.18, 15.19, 15.20

class Base {
public:
    void pub_mem() {
        cout << "Base pub_mem()" << endl;
    }
protected:
    void prot_mem() {
        cout << "Base prot_mem()" << endl;
    }
private:
    void priv_mem() {
        cout << "Base priv_mem()" << endl;
    }
};

struct Pub_Derv : public Base {
    void f() { prot_mem(); }

    //inaccessible
//    char g() { return priv_mem; }

    void memfcn(Base &b) { b = *this; }
};


struct Prot_Derv : protected Base {
    void f() { prot_mem(); }

    void memfcn(Base &b) { b = *this; }
};


struct Priv_Derv : private Base {
    void f1() { prot_mem(); }

    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
    void use_base() {
        prot_mem();
    }

    void memfcn(Base &b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
    void use_base() {
        prot_mem();
    }
};

struct Derived_from_private : public Priv_Derv {
    //wrong, Base::prot_mem() is private in Priv_Derv
//    void use_case() {
//        prot_mem();
//    }

    //wrong, Base is an inaccessible base of Derived_from_private
//    void memfcn(Base &b) { b = *this; }
};
#endif // TEST15_18_BASE_H
