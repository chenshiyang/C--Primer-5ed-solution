#include<iostream>
#include<string>

using namespace std;

int main() {
//    string s1;
//    string s2 = s1;
//    string s3 = "hiya";
//    string s4(10, 'c');
//    cout << s1 << endl;
//    cout << s2 << endl;
//    cout << s3 << endl;
//    cout << s4 << endl;
//    string s5;
//    cin >> s5;
//    cout << s5 << endl;
//    cout << s3.size() << endl;

//    string line;
//    while(getline(cin, line)) {
//        for(string::size_type i = 0; i < line.size(); ++ i) {
//            cout << line[i] << endl;
//        }
//    }


//    string s;
//    getline(cin, s);
//    for(auto &c : s) {
//        c = toupper(c);
//    }
//    cout << s << endl;

//    string s;
//    cout << s[0] << endl;
//    cout << "hello" << endl;

////test.310
//    string s;
//    cin >> s;
//    string res;
//    for(auto &c : s) {
//        if(!ispunct(c))  {
//            res += c;
//        }
//    }
//    cout << res << endl;

    const string s = "keep on";
    for(auto &c : s) {
        cout << c;
    }

    return 0;
}
