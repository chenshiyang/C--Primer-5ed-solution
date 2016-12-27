#include <iostream>
#include <random>
#include <string>

using namespace std;


bool play(bool first) {
    static default_random_engine e;
    static bernoulli_distribution b;
    return b(e);
}


int main() {
    string resp;
    static default_random_engine e;
    static bernoulli_distribution b;
    do {
        bool first = b(e);
        cout << first << endl;
        cout << (first ? "We go first"
                 : "You get to go first") << endl;
        cout << (play(first) ? "Sorry, you lost"
                 : "Congrats, you won") << endl;
        cout << "Play again? Enter 'yes' or 'no'" << endl;
    } while(cin >> resp && resp[0] == 'y');
    return 0;
}
