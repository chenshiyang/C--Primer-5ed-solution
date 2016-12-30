#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Base1 {
    void print(int i) const {
        cout << "Base1::print(int)" << endl;
    }

protected:
    int ival;
    double dval;
    char cval;
private:
    int *id;
};

struct Base2 {
    void print(double d) const {
        cout << "Base2::print(double)" << endl;
    }
protected:
    double fval;
private:
    double dval;
};

struct Derived : public Base1 {
    void print(string s) const {
        cout << "Derived::print(string)" << endl;
    }
protected:
    string sval;
    double dval;
};

struct MI : public Derived, public Base2 {
    void print(vector<double> dvec) {
        cout << "MI::print(vector<double>)" << endl;
    }

    //for test 18.26
    void print(int i) const {
        cout << "MI::print(int)" << endl;
        Base1::print(i);
    }
    void foo(double);

protected:
    int *ival;
    vector<double> dvec;
};

int ival;
double dval;

//for test 18.27
void MI::foo(double cval) {
    int dval;
    dval = Base1::dval + Derived::dval;
    Base2::fval = dvec[dvec.size() - 1];
    sval[0] = Base1::cval;
}

int main() {
    MI mi;
    mi.print(42);

    return 0;
}
