#include <iostream>
#include <string>
#include "Array.h"

int main()
{
    int data_1[]{ 2, 3, 4, 5 };
    Array<int> arr_i_1(4);
    Array<int> arr_i_2(data_1, 4);
    arr_i_2.push_back (10);
    arr_i_2.at(10);
    arr_i_2.print_arr();
    arr_i_2.clear();

    double data_2[] {2.1, 3.1, 4.1, 5.1};
    Array<double> arr_d_1 (3);
    Array<double> arr_d_2 (data_2, 4);
    arr_d_2.push_front (6.6);
    arr_d_2.print_arr();

    std::string data_3[] { "C++", "is", "very", "hard"};
    Array<std::string> arr_str_1(3);
    Array<std::string> arr_str_2(data_3, 4);
    arr_str_2.pop_front();
    arr_str_2.pop_back();
    std::string str {"Pyton"};
    arr_str_2.insert(str, 1);
    std::string str_1 {"easy" };
    arr_str_2.insert(str_1, 5);
    arr_str_2.print_arr();

    return 0;
}