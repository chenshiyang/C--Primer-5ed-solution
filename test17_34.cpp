#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << boolalpha << "boolalpha: " << true << " " << false << "\n";
    cout << noboolalpha << "noboolalpha: " << true << " " << false << "\n";
    cout << showbase << "showbase: " << 20 << " " << 1024 << "\n";
    cout << noshowbase << "noshowbase: " << 20 << " " << 1024 << "\n";
    cout << showpoint << "showpoint: " << 3.14 << " " << 5.0 << "\n";
    cout << noshowpoint << "noshowpoint: " << 3.14 << " " << 5.0 << "\n";
    cout << showpoint << "showpos: " << 566 << " " << 666 << "\n";
    cout << noshowpos << "noshowpos: " << 566 << " " << 666 << "\n";
    cout << uppercase << hex << scientific << 20 << " " << 3.14 << "\n";
//    cout << nouppercase << dec << defaultfloat;
    cout << 20 << " " << 3.14 << "\n";
    cout << dec << "decimal: " << 20 << " " << 1024 << "\n";
    cout << oct << "octal: " << 20 << " " << 1024 << "\n";
    cout << hex << "hex: " << 20 << " " << 1024 << "\n";
    cout << dec;
    int i = -16;
    double d = 3.14159;
    cout << "i: " << setw(12) << i << "next col" << "\n"
    << "d: " << setw(12) << d << "next col" << "\n";
    cout << left
        << "i: " << setw(12) << i << "next col" << "\n"
        << "d: " << setw(12) << d << "next col" << "\n"
        << right;
    cout << right
        << "i: " << setw(12) << i << "next col" << "\n"
        << "d: " << setw(12) << d << "next col" << "\n";
    cout << internal
        << "i: " << setw(12) << i << "next col" << "\n"
        << "d: " << setw(12) << d << "next col" << "\n";
    cout << setfill('*')
        << "i: " << setw(12) << i << "next col" << "\n"
        << "d: " << setw(12) << d << "next col" << "\n"
        << setfill(' ');
    cout << setbase(2) << "setbase(2) " << 1024 << " " << 20 << "\n";
    cout << setbase(10) << "setbase(10)" << 1024 << " " << 20 << "\n";
    cout << skipws << "skipws: ";
    char ch;
    while(cin >> ch) {
        cout << ch;
    }
    cout << noskipws << "noskipws: " << endl;
    while(cin >> ch) {
        cout << ch;
    }
    return 0;
}
