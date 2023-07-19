#include <iostream>
#include <string>
#include "Array.h"

int main()
{
    int data_1[]{ 2, 3, 4, 5 };
    Array<int> arr_i_1(3);
    Array<int> arr_i_2(data_1, 4);
    std::cout << arr_i_2.at(1) << "\n";

    double data_2[] {2.1, 3.1, 4.1, 5.1};
    Array<double> arr_d_1 (3);
    Array<double> arr_d_2 (data_2, 4);
    std::cout << arr_d_2.at(1) << "\n";

    std::string data_3[] { "C++", "is", "very", "hard"};
    Array<std::string> arr_str_1(3);
    Array<std::string> arr_str_2(data_3, 4);
    std::cout << arr_str_2.at(1) << "\n";
    
    return 0;
}