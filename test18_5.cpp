#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <typeinfo>  //std::bad_cast

using namespace std;

int main() {
    try {
        cout << "trying" << endl;
        throw range_error("range error");
    } catch(range_error &e) {
        cout << e.what() << endl;
        abort();
    } catch(underflow_error &e) {
        cout << e.what() << endl;
        abort();
    } catch(overflow_error &e) {
        cout << e.what() << endl;
        abort();
    } catch(runtime_error &e) {
        cout << e.what() << endl;
        abort();
    } catch(length_error &e) {
        cout << e.what() << endl;
        abort();
    } catch(out_of_range &e) {
        cout << e.what() << endl;
        abort();
    } catch(invalid_argument &e) {
        cout << e.what() << endl;
        abort();
    } catch(domain_error &e) {
        cout << e.what() << endl;
        abort();
    } catch(logic_error &e) {
        cout << e.what() << endl;
        abort();
    } catch(bad_cast &e) {
        cout << e.what() << endl;
        abort();
    } catch(bad_alloc &e) {
        cout << e.what() << endl;
        abort();
    } catch(exception &e) {
        cout << e.what() << endl;
        abort();
    }
    return 0;
}
