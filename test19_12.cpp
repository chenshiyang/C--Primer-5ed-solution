#include <iostream>
#include <string>
#include "test19_12_Screen.h"

using namespace std;

void ptrTest() {
    const string Screen::*pdata;
    pdata = &Screen::contents;
    Screen myScreen(10, 10, '*'), *pScreen = &myScreen;
    auto s = myScreen.*pdata;
    cout << s << endl;
    cout << pScreen ->* pdata;
}

int main() {
    ptrTest();
    return 0;
}

