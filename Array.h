#pragma once
#include <iostream>
#include <string>

template <typename T>
class Array
{   
    public:
        Array () = default;
        Array (int length);
        Array (T data[], int length);
        Array (Array <T>& other_arr);
        ~Array () { delete data_; }      

        const int get_length() { return length_; }
        T at(int index);
   
    private:
        T *data_ {};
        int length_;
};

template <>
Array <std::string>::~Array() = default;
