#include <iostream>

using namespace std;

int main() {
    cout << uppercase << showbase;
    cout << "default: " << 20 << " " << 1024 << endl;
//    cout << "in binary: " <<  << 20 << " " << 1024 << endl;
    cout << "in octal: " << oct << 20 << " " << 1024 << endl;
    cout << "in hex: " << hex << 20 << " " << 1024 << endl;
    cout << "in decimal: " << dec << 20 << " " << 1024 << endl;
    cout << nouppercase << noshowbase << dec << endl;
    return 0;
}
