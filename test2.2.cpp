#include<iostream>

std::string global_str;
int global_int;
extern int j = 5;
int i = 5;

int main() {
//    std::cin >> int input_value;
//    std::cout << input_value;
    int local_int;
    std::string local_str;
    std::cout << "hello";
    std::cout << global_str << std::endl;
    std::cout << global_int << std::endl;
    std::cout << local_str << std::endl;
    std::cout << local_int << std::endl;
    std::cout << "hello";

    int i = 100;
    int j = i;
    std::cout << j << std::endl;

    int val = 5;
    int &refval = val;
    std::cout << refval << std::endl;
    int &rrefval = &refval;
    std::cout << rrefval << std::endl;
}
