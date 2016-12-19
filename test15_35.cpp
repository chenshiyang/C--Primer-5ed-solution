
#include <string>

#include "test15_Query_base.h"

using namespace std;

int main() {

    //test 15.38
//    BinaryQuery a = Query("fiery") & Query("bird");
//    AndQuery b = Query("fiery") & Query("bird");
//    OrQuery c = Query("fiery") & Query("bird");

    //test 15.35, 15.39
    string path("test12text.txt");
    ifstream in_file(path);
    TextQuery tq(in_file);
    Query q = Query("a") & Query("the") | Query("it");
    cout << q << endl;
    print(cout, q.eval(tq));
    return 0;
}
