#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

//test 6.51
//    int f() {
//        cout << "f()" << endl;
//        return 0;
//    }
//
//    int f(int x) {
//        cout << "f(int x)" << endl;
//        return 0;
//    }
//
//    int f(int x, int y) {
//        cout << "f(int x, int y)" << endl;
//        return 0;
//    }
//
//    int f(double d, double y = 3.14) {
//        cout << "f(double d, double y = 3.14)" << endl;
//        return 0;
//    }

//test 6.54
    int add(int x, int y) {
        cout << "add function" << endl;
        return x + y;
    }

    int substract(int x, int y) {
        cout << "substract function" << endl;
        return x - y;
    }

    int multiply(int x, int y) {
        cout << "multiply function" << endl;
        return x * y;
    }

    int division(int x, int y) {
        cout << "division function" << endl;
        return x / y;
    }

//int binarySearch(vector<int> ivec, int target) {
//    auto beg = ivec.cbegin(), end = ivec.cend();
//    auto mid = ivec.cbegin() + (end - beg) / 2;
//    while(mid != end && *mid != target) {
//        if(target < * mid) {
//            end = mid;
//        }
//        else {
//            beg = mid + 1;
//        }
//        mid = beg + (end - beg) / 2;
//    }
//    if(*mid == target) {
//        return (mid - ivec.cbegin());
//    }
//    else {
//        return -1;
//    }
//}

//test 6.10
//swap two number using pointer
//void swap(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//    return;
//}

//swap two number using reference
//void swap2(int &a, int &b) {
//    int temp = a;
//    a = b;
//    b = temp;
//    return;
//}

int main()
{
//    vector<string> v1{"a", "b"};
//    for(string s : v1) {
//        cout << s << endl;
//    }
//
//    vector<string> v2(v1);
//    for(string s : v2) {
//        cout << s << endl;
//    }
//
//    vector<string> v3(3, "hi");
//    for(string s : v3) {
//        cout << s << endl;
//    }

//    vector<int> int_list;
//    int integer;
//    while(cin >> integer) {
//        int_list.push_back(integer);
//    }
//    for(auto i : int_list) {
//        cout << i << endl;
//    }
//
//    cout << "Is list empty ? " << int_list.empty() << endl;
//    cout << "There are " << int_list.size() << " elements in list." << endl;
//    cout << "The first element in int_list is " << int_list[0] << endl;
//
//    for(auto i : int_list) {
//        i *= i;
//    }
//
//    for(auto i : int_list) {
//        cout << i << endl;
//    }
//
//    for(auto &i : int_list) {
//        i *= i;
//    }
//
//    for(auto &i : int_list) {
//        cout << i << endl;
//    }

    //越界访问一个不存在的值。编译通过，但值是未定义的。
//     cout << int_list[10];

    //est3.17 读入词，把每个词转化成大写形式，并输出。
//    vector<string> string_list;
//    string ss;
//    while(cin >> ss) {
//        string_list.push_back(ss);
//    }
//
//    for(auto &s : string_list) {
//        for(auto &c : s){
//            c = toupper(c);
//        }
//    }
//
//    for(auto &s : string_list) {
//        cout << s << endl;
//    }

    //iterator test
//    string s("something important.");
//    if(s.begin() != s.end()) {
//        auto it = s.begin();
//        *it = toupper(*it);
//    }
//
//    cout << s << endl;
//
//    auto it2 = s.end();
//    cout << *it2 << endl;
//    -- it2;
//    cout << *it2 << endl;
//    --it2;
//    --it2;
//    ++it2;
//    ++it2;
//    ++it2;
//    ++it2;
//    cout << *it2 << endl;
//
//    vector<string> svec{"there", "are", "something", "important"};
//    auto sit = svec.begin();
//    cout << (*sit).empty() << endl;
//    cout << sit->empty() << endl;

//  test 3.23
//    vector<int> ivec(10, 9);
//    for(auto it = ivec.begin(); it != ivec.end(); ++it) {
//        (*it) *= 2;
//    }
//    for(auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
//        cout << *it << endl;
//    }

//    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
//    auto it1 = ivec.begin();
//    auto it2 = ivec.end();
//    cout << (it1 < it2) << endl;
//    cout << (it1 - it2) << endl;
//    cout << *it1 << endl;
//    cout << *(it1 + 4) << endl;
//    cout << *(it2 - 3) << endl;


//binary search test
//    vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    cout << binarySearch(ivec, 5) << endl;
//    cout << binarySearch(ivec, 6) << endl;
//    cout << binarySearch(ivec, 7) << endl;
//    cout << binarySearch(ivec, 10) << endl;
//    cout << binarySearch(ivec, 1) << endl;
//    cout << binarySearch(ivec, 12) << endl;


//pointer and array test.
//    string nums[] = {"one", "two", "three", "four"};
//    string *p = &nums[0];
//    cout << *p << " " << *(p + 1) << endl;
//    string *p2 = nums;
//    cout << *p2 << " " << *(p + 1) << endl;
//    auto p3(nums);//p3是个指向数组nums首元素的指针
//    cout << *p3 << " " << p3 << endl;
//
//    string *p4 = p3 + 4;
//    cout << *p4 << endl;
//    string *p5 = p3 + 6;//越界,输出结果为定义
//    cout << *p5 << endl;

//char 数组应以\0结尾，否则strlen()结果是未定义的。
//    cout << strlen("Hello") << endl;
//    char chars[] = {'H', 'e', 'l', 'l', 'o', 'w'};
//    cout << strlen(chars

// 不要再cout中改变i
//    int i = 0;
//    cout << i << " " << ++i << endl;

//bool类型不应参与算术运算
//    bool b = true;
//    bool b2 = -b;
//    bool b3 = !b;
//    cout << b2 << " " << b3 << endl;

//    cout << (30 / 3 * 21 % 5) << endl;
//
//    int i;
//    double d;
//    d = i = 3.5;
//    cout << d << " " << i;
//    i = d = 3.5;
//    cout << d << " " << i;

//    int ival = 1;
//    cout << (ival-- && ival) << endl;

//test4.21
//vector<int> ivec = {1, 2, 3, 4, 5};
//for(auto &i : ivec) {
//    i *= (i % 2 == 0? 1 : 2);
//}
//for(const auto &i : ivec) {
//    cout << i << " ";
//}
//cout << endl;

//test4.23 + 的优先级比==高

//test on sizeof() function
//    int i = 5;
//    int *p = &i;
//    char c = 'a';
//    long l = 100L;
//    float f = 3.13f;
//    double d = 3.14;
//    short s = 4;
//    int array[] = {1, 2, 3, 4, 5};
//    string str = "Hello";
//    vector<int> ivec = {1, 2, 3, 4, 5};
//    vector<string> svec = {"Hello", "World"};
//    cout << sizeof(i) << " ";
//    cout << sizeof(p) << " ";
//    cout << sizeof(*p) << " ";
//    cout << sizeof(c) << " ";
//    cout << sizeof(l) << " ";
//    cout << sizeof(f) << " ";
//    cout << sizeof(d) << " ";
//    cout << sizeof(s) << " ";
//    cout << sizeof(array) << " ";
//    cout << sizeof(str) << " ";
//    cout << sizeof(ivec) << " ";
//    cout <<sizeof(svec) << endl;

//test 4.29
//    int x[10];
//    int *p = x;
//    cout << sizeof(x) / sizeof(*x) << endl;
//    cout << sizeof(p) / sizeof(*p) << endl;

//test 4.33
//    int x = 0, y = 0;
//    false ? ++x, ++y : --x, --y; //等价于 (false ? ++x, ++y : --x), --y;
//    cout << "x: " << x << " , y: " << y << endl;//因此当rue时， ++x,  --++y, 表达式返回的结果是y   当false时, --x, --y,表达式返回的结果仍是y

//函数中的内置类型局部变量没有初始化，则执行默认初始化，值是未定义的。
//函数中的内置类型静态局部变量如果没有初始化，则执行值初始化，值为0.
//函数中的类局部变量如果没有初始化，则按照默认构造函数初始化，string默认构造函数初始化为空。
//    int i;
//    cout << i <<endl;
//    static int j;
//    cout << j <<endl;
//    string s;
//    cout << s << s.empty() << endl;
//    static string ss;
//    cout << ss << ss.empty() << endl;

//test6.10
//    int a = 5;
//    int b = 6;
//    swap(&a, &b);//为什么这里改成swap(a, b)也可以？
//    cout << a << " " << b << endl;//a will be 6, b will be 5
//    swap2(a, b);
//    cout << a << " " << b << endl;// a will be back to 5, b will be 6


//test P191
//    int i = 42;
//    const int *cp = &i;
//    int *p = &i;


//test 6.51
//    f(5.6);
////    f(2.56, 42);//call to 'f' is ambiguous
//    f(42);
//    f(42, 0);
//    f(2.56, 3.14);

//test 6.55&6.54
//solution 1
//    typedef int (*func)(int, int);
//    int a = 3, b = 4;
//    vector<func> fpvec = {};
//    fpvec.push_back(add);
//    fpvec.push_back(substract);
//    fpvec.push_back(multiply);
//    fpvec.push_back(division);
//    for(auto e : fpvec) {
//        cout << e(a, b) << endl;
//    }

//solution 2
//    typedef int func(int, int);
//    int a = 3, b = 4;
//    vector<func*> fpvec = {};//显示声明指针
//    fpvec.push_back(add);
//    fpvec.push_back(substract);
//    fpvec.push_back(multiply);
//    fpvec.push_back(division);
//    for(auto e : fpvec) {
//        cout << e(a, b) << endl;
//    }

    return 0;
}


