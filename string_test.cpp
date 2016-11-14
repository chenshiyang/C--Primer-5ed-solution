#include <iostream>
#include <string>
//#include <cctype>
#include <vector>
using namespace std;

int main()
{
//    string s1 = "hello, c++";
//    cout << "s1 : " << s1 << endl;
//    string s2 = "hello, java is better";
//    cout << "s2 : " << s2 << endl;
//    cout << "s1 is empty ? " << s1.empty() << endl;
//    cout << "s2.size is " << s2.size() << endl;
//    string s3 = s1 + s2;
//    cout << "s3 : " << s3 << endl;
//    cout << "s1 == s2 ? " << (s1 == s2) << endl;// ==表达式里的()不加会编译出错
//    cout << "second char of c2 is " << s2[2] <<endl;
//    string s4, s5;
//    cout << "please input s4 " << endl;
//    cin >> s4;
//    cout << s4 << endl;
//    cout << "please input s5 " << endl;
//    cin >> s5;
//    cout << s5 << endl;
//    cout << "s4 == s5 ? " << (s4 == s5) << endl;// ==表达式里的()不加会编译出错

//    string line;
//    while(getline(cin, line)){
//        cout << line << "line size is " << line.size() << endl;
//    }

//    string str("Some string");
//    decltype(str.size()) cnt = 0;
//    for(auto &c : str){
//        if(islower(c)){
//                c = toupper(c);
//            cnt ++;
//        }
//    }
//    cout << "The number of punctions is " << cnt << endl;
//    cout << str << endl;

//    const string s = "Keep out";
//    for (auto &c : s) {
//        c = toupper(c);
//        cout << c << endl;
//    }

//    string s2 = "Some, thing, is, good.";
//    for (decltype(s2.size()) i = s2.size() - 1; i >= 0; i --) {
//        if(ispunct(s2[i])) {
//            s2[i] = ' ';
//        }
//    }
//    cout << s2;

    int a = 3, b = 4, c = 5;
    double d = 6.0;
    vector<int> v1 = {a, b, c};
    vector<int> v2 = (v1);
    vector<int> v3(5);
    for(auto i : v3){
        cout << i << endl;
    }

    vector<string> svec1(5, "Hi");
    for(auto s : svec1){
        cout << s << endl;
    }

    vector<string> svec2{3};
    vector<string> svec3{"Ha", "Hello"};
    for(auto s : svec2){
        cout << s << 1 << endl;
    }

    for(auto s : svec3) {
        cout << s << endl;
    }

    vector<string> svec4{"He"};
    return 0;
}
