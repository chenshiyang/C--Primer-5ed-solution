#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {
    vector<int> ivec = {1, 2, 3, 5, 8, 13, 21};
    unsigned long val = 0UL;
    for(auto i : ivec) {
        val |= 1UL << i;
    }
    cout << val << endl;
    bitset<32> b(val);
    cout << b << endl;

    bitset<32> bb;
    for(auto i : ivec) {
        bb.set(i);
    }
    cout << bb << endl;
    if(b == bb) {
        cout << "b == bb" << endl;
    }
}
