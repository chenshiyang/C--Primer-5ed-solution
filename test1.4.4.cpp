#include <iostream>
using namespace std;

int main()
{
    int cur = 0, val = 0;
    if(cin >> cur) {
        int cnt = 1;
        while(cin >> val) {
            if(cur == val) {
                cnt ++;
            }
            else {
                cout << cur << " occurs " << cnt << " times" << endl;
                cnt = 1;
                cur = val;
            }
        }
        cout << cur << " occurs " << cnt << " times" << endl;
    }
}
