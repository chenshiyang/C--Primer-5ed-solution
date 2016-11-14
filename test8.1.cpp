#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//test 8.1
//istream& readAndOutput(istream &is) {
//    string s;
//    while(is >> s) {
//        cout << s << endl;
//    }
//    is.clear();
//    return is;
//}

int main() {
//test 8.1
//    readAndOutput(cin);
//    int i = 0;
//    while(cin >> i) {
//        cout << i << endl;
//    }
//    cout << "end" <<endl;

//test if cin is related to cout
//    ostream *old_tie = cin.tie(nullptr);
//    if(*old_tie == cout) {
//        cout << "yes" << endl;
//    }
//    else {
//        cout << "no" << endl;
//    }

//test open a ofstream, and write data into it.
//open a ifstream, and read from it.
    string file("test8_2.txt");
    cout << file << endl;
    ofstream ofs(file);
    ofs << "hello" << endl;
    ofs.close();
    ifstream ifs(file);
    string ss;
    while(ifs >> ss) {
        cout << ss << endl;
    }


}
