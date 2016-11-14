#include<iostream>
#include<vector>
#include<string>

using namespace std;

class NoDefault {
public:
    NoDefault(int i) : val(i) { cout << "NoDefault(int i)" << endl;}

private:
    int val;
};

class C {
public:
    C() : nd(0) { cout << "C()" << endl;}

private:
    NoDefault nd;
};

int main() {
    C c;
    vector<NoDefault> vec(10);
    return 0;
}
