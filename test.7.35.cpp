#include<iostream>
#include<string>

using namespace std;

//typedef string Type;
//Type initVal();

class Exercise {
public:
    typedef double Type;
    Type initVal();
    Type setVal(Type);


private:
    Type val;
};

Exercise::Type Exercise::initVal() {
    return 0.1;
}

Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}

int main() {
    return 0;
}
