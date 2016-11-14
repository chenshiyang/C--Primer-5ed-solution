#include<iostream>
#include<string>
#include<vector>

using namespace std;

//test p 182 factorial
int fact(int &val) {//show the effect of passed by reference
    int re = 1;
    while(val > 1) {
        re *= val --;
    }
    return re;
}

//test p 185
size_t count_calls() {
    static size_t ctr = 0;
    return ++ctr;
}

//test 6.10
void swap(int *p1, int *p2) {//swap using pointer
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swap(int &r1, int &r2) {//swap using reference
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

//test 6.17
//check if a string constains a Upper letter.
bool containUpper(const string &s) {
    for(auto &c : s) {
        if(isupper(c)) {
            return true;
        }
    }
    return false;
}
//test 6.17 change all letters in a string into lower
void toLower(string &s) {
    for(auto &c : s) {
        c = tolower(c);
    }
}

//test 6.19
int count(const string& s, char c) {return 0;}
double calc(double d) {return d;}
int sum(vector<int>::iterator beg, vector<int>::iterator end, int ival) {
    return ival;
}

//test 6.22 swap two pointers

void swapPointers(int *(&p1), int *(&p2)) {
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}

//test 6.27
int getSum(initializer_list<int> il) {
    int sum = 0;
    for(auto beg = il.begin(); beg != il.end(); ++beg) {
        sum += *beg;
    }
    return sum;
}

//test 6.32
int &get(int *array, int index) {
    return array[index];
}


//test p206
    int array[] = {1, 2, 3};
    decltype(array) &arrRefe(int (&array) [3] ) {
        return array;
    }

//test p221
    int function1() { return 0;}

int main() {
    //test p182
//    int i = 5;
//    cout << fact(i) << endl;
//    cout << i << endl;

//test p185
//    for(size_t i = 0; i != 10; ++i) {
//        cout << count_calls() << endl;
//    }

//test 6.10
//    int a = 5, b = 6;
//    swap(&a, &b);
//    cout << a << " " << b << endl;
//    swap(a, b);
//    cout << a << " " << b << endl;

//test 6.17
//    string s{"My name is csy"};
//    cout << containUpper(s) << endl;
//    toLower(s);
//    cout << s << endl;
//    cout << containUpper(s) << endl;

//test6.19
//    vector<int> vec(10);
//    count("abcda", 'a');
//    calc(66);
//    cout << sum(vec.begin(), vec.end(), 3.8) << endl;



//test 6.22 swap two pointers
//    int i = 5, j = 6;
//    int *p1 = &i;
//    int *p2 = &j;
//    cout << p1 << endl;
//    cout << p2 << endl;
//    swapPointers(p1, p2);
//    cout << *p1 << " " << *p2 << endl;
//    cout << p1 << endl;
//    cout << p2 << endl;

//test 6.27
//    cout << getSum({1, 2, 3, 4, 5}) << endl;

//test 6.32
//    int ia[10];
//    for(int i = 0; i != 10; ++i) {
//        get(ia, i) = i;
//    }
//    for(auto i : ia) {
//        cout << i << endl;
//    }

//test p 221 function pointer and array pointers
//    int array[2] = {1, 2};
//    int *pa = array;
//    //int *pa = &array;//wrong
//    int (*pa2)[2] = &array;
//    cout << *pa << " " << *(pa + 1) << endl;
//    cout << (*pa2)[1] << endl;

    int (*pf)();//declare a function pointer
    pf = function1;// point to
    cout << (*pf)() << endl;
    cout << pf() << endl;

        return 0;
}


