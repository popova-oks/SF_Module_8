#include <iostream>
#include <string>
#include "Array.h"

Array<int> get_newIntArr()
{
    int data[] {6, 7, 8};
    return Array<int> (data, 3);
}

Array<double> get_newDblArr()
{
    double data[] {7.7, 8.8, 9.9};
    return Array<double> (data, 3);
}

int main()
{    
    std::cout << "-------------------------------------------------\n";
    Array<int> arr_i_1(4);
    arr_i_1.insert (11, 2);
    arr_i_1.insert (12, 6);
    arr_i_1.print_arr();

    int data_1[]{ 2, 3, 4, 5 };
    Array<int> arr_i_2(data_1, 4);
    arr_i_2.push_back (10);
    //arr_i_2.at(10);
    arr_i_2.print_arr();

    arr_i_2.clear();
    arr_i_2.push_back(20);
    arr_i_2.push_front(10);    
    arr_i_2.print_arr();

    Array<int> arr_i_3 = get_newIntArr();
    arr_i_3.print_arr();

    Array<double> arr_d_1 (3);
    arr_d_1.replace (11.1, 1);
    arr_d_1.replace(22.2, 2);
    arr_d_1.replace(33.3, 3);
    arr_d_1.print_arr();

    double data_2[] {2.1, 3.1, 4.1, 5.1};
    Array<double> arr_d_2 (data_2, 4);
    arr_d_2.push_front (6.6);
    arr_d_2.print_arr();

    Array<double> arr_d_3;
    arr_d_3 = get_newDblArr();
    arr_d_3.print_arr();
    
    std::string data_3[] { "Java", "is", "not", "hard"};
    Array<std::string> arr_str(data_3, 4);
    Array<std::string> arr_str_1(3);
    arr_str_1 = std::move (arr_str);
    arr_str_1.print_arr();

    std::string data_4[] { "C++", "is", "very", "hard"};
    Array<std::string> arr_str_2(data_4, 4);

    Array<std::string> arr_str_3;
    arr_str_3 = arr_str_2;
    arr_str_3.print_arr();

    arr_str_2.pop_front();
    arr_str_2.pop_back();
    std::string str {"Pyton"};
    arr_str_2.insert(str, 1);
    std::string str_1 {"easy" };
    arr_str_2.insert(str_1, 5);
    arr_str_2.print_arr();    

    return 0;
}
