#include <iostream>

using namespace std;

struct Base {
    void bar(int i) {
        cout << "Base::bar(int)" << endl;
    }
protected:
    int ival = 0;
};

struct Derived1 : virtual public Base {
    void bar(char c) {
        cout << "Derived1::bar(char)" << endl;
    }
    void foo(char c) {
        cout << "Derived1::foo(char)" << endl;
    }
protected:
    char cval = 'c';
};
struct Derived2 : virtual public Base {
    void foo(int i) {
        cout << "Derived2::foo(int)" << endl;
    }
protected:
    int ival = 1;
    char cval = 'd';
};
class VMI : public Derived1, public Derived2 {
public:
    void access_ival() {
        cout << Base::ival << endl;//without Base::, it will be Derived2::ival
    }

    void access_cval() {
        cout << Derived1::cval << endl;//both cval need ::
    }
};

int main() {
    VMI vmi;
    vmi.access_ival();
    vmi.access_cval();
    vmi.Derived1::foo('c');//both need ::
    vmi.bar(1);//call Derived1::bar()
    vmi.bar('c');//call Derived1::bar()
    vmi.Base::bar(1);


    return 0;
}
